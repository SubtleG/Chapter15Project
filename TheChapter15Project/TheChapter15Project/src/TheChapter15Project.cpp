//*****************
//Project Name: Chapter 15
//Project Description: Order system
//Project Author: Hoecker, Bryce
//Is this an extra credit Project:
//Date completed: 11/15/2017
//Operating system used: Windows
//IDE Used:  Eclipse neon
//*****************
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include "Order.hpp"
#include "OrderItem.hpp"
#include "FoodItem.hpp"
#include "ElectronicItem.hpp"
#include "MediaItem.hpp"
#include "Date.hpp"
#include "Customer.hpp"
#include <memory>
using namespace std;

void printFood(vector<OrderItem*> ordPtr, string);
void printMedia(vector<OrderItem*> ordPtr, string);
void printElectronics(vector<OrderItem*> ordPtr, string);
//const char* stoc(string);
//string ctos(const char*[], int);

int main(int argc, const char *argv[]) {

	//#7
	if (argc > 2 || argc < 1){
		cout <<"Error! Invalid number of arguments." << endl;
		return 1;
	}

	//#1
	vector<Customer*> theCustomers;
	//Customer *tempCust = new Customer();

	//#2
	ifstream custFile;
	custFile.open("CustomerFile.txt");
	if (custFile.fail()){
		cout << "Error opening file " << endl;
	}
	else{
		while(!(custFile.eof())){
			string custNum, custName, custEmail;
			int year, month, day;
//			//test for infinite loop
//			cout << "custLoop" << endl;
			custFile >> custNum >> custName >> custEmail >> year >> month >> day;
			Customer *custNum1 = new Customer;
			custNum1->setCustomerNumber(custNum);
			custNum1->setCustomerName(custName);
			custNum1->setEmail(custEmail);
			Date custJoin(day, month, year);
			custNum1->setDateJoined(custJoin);
			theCustomers.push_back(custNum1);
		}
    	custFile.close();
	}
//	tempCust = nullptr;
//	delete []tempCust;

	//#3
	//Dumb pointer
	//vector<Order*> theOrders;

	//Smart Pointer
	vector<unique_ptr<Order>> theOrders;
//	Order *tempOrder = new Order();

	//#4
	ifstream orderFile;
	orderFile.open("OrderFile.txt");
	if (orderFile.fail()){
		cout << "Error opening file " << endl;
	}
	else{
		while(!(orderFile.eof())){
//			//test for infinite loop
//			cout << "orderLoop" << endl;
			string ordID, custNum;
			int ordYear, ordMonth, ordDay;
			orderFile >> ordID >> ordYear >> ordMonth >> ordDay >> custNum;
			// can check for existing customer with custNum to see if they exist
//			// Dumb Pointer
//			// START MEMORY LEAK
//			//Order *tempOrder = new Order(&theCustomers, custNum, ordID);
//			// END MEMORY LEAK

			// Smart Pointer
			unique_ptr<Order>tempOrder(new Order(&theCustomers, custNum, ordID));

//			//Order ordNum1(theCustomers, custNum)
//			"FAILFAILFAIL"
			if(tempOrder->getOrderNumber() == "FAILFAILFAIL"){
//				// Dumb Pointer?
//				delete tempOrder;
			}
			else{
				tempOrder->setOrderNumber(ordID);
				Date ordDate(ordDay, ordMonth, ordYear);
				tempOrder->setOrderDate(ordDate);
//				//Dumb Pointer
//				theOrders.push_back(tempOrder);
				//Smart Pointer

				//Debugger terminates here 8:32pm....
				theOrders.push_back(move(tempOrder));
			}
		}
    	orderFile.close();
	}
//	tempOrder = nullptr;
//	delete []tempOrder;


	//#7
	unsigned int numTimes = theOrders.size();
	int ordPlaceNum = 0;
	if (argc == 2){
		//Only print the order that was sent in
		for(unsigned int i = 0; i < numTimes; i++){
			//const char* tempCha = (theOrders[i]->getOrderNumber()).c_str();
			//cout << argv[argc] << endl;
			if(theOrders[i]->getOrderNumber() == argv[argc-1]){
				ordPlaceNum = i;
				numTimes = i+1;
				break;
			}
		}
		if(numTimes > theOrders.size()){
			cout << "Couldn't find that order" << endl;
			return 1;
		}

	}
	if (argc == 1){
		//Print everything
		unsigned int numTimes = theOrders.size();
		//numTimes isn't used?
		numTimes += 1;
		numTimes -= 1;
	}

	//#5
	//Prints out the order report
	cout << endl;
	cout << "Order Report:" << endl;


	for(unsigned int i = ordPlaceNum; i < numTimes; i++){
		vector<OrderItem*>tempVect = theOrders[i]->getItemsInOrder();
		bool haveFood = false;
		bool haveMedia = false;
		bool haveElec = false;
		for(unsigned int c = 0; c < tempVect.size(); c++){
			if(tempVect[c]->whoAmI() == "FoodItem"){
				haveFood = true;
			}
			if(tempVect[c]->whoAmI() == "MediaItem"){
				haveMedia = true;
			}
			if(tempVect[c]->whoAmI() == "ElectronicItem"){
				haveElec = true;
			}
		}
		cout << "==============================" << endl;
		cout << setw(15) << "Order ID" << setw(20) << "Customer ID" << setw(20) << "Order Date" << setw(40) << "Customer" << endl;
		cout << setw(15) << "--------" << setw(20) << "-----------" << setw(20) << "----------" << setw(40) << "--------" << endl;
		cout << setw(15) << theOrders[i]->getOrderNumber() << setw(20) << theOrders[i]->getOrderCustomer().getCustomerNumber() << setw(20) << theOrders[i]->getOrderDate().getDateString()
			<< setw(40) << theOrders[i]->getOrderCustomer().getCustomerName() << endl;


		if(haveFood){
			//FoodItems
			cout << "---------------" << endl;
			cout << setw(20) << "Food Items Ordered: " << setw(20) << "Item Number" << setw(40) << "Item Description" << setw(20) << "Calories" << setw(10) << "Cost" << endl;
			cout << setw(20) << "                   " << setw(20) << "-----------" << setw(40) << "----------------" << setw(20) << "--------" << setw(10) << "----" << endl;
			printFood(tempVect, theOrders[i]->getOrderNumber());
		}
		if(haveMedia){
			//MediaItems
			cout << "---------------" << endl;
			cout << setw(20) << "Media Items Ordered:" << setw(20) << "Item Number" << setw(40) << "Item Description" << setw(20) << "ISBN" << setw(10) << "Cost" << endl;
			cout << setw(20) << "                    " << setw(20) << "-----------" << setw(40) << "----------------" << setw(20) << "----" << setw(10) << "----" << endl;
			printMedia(tempVect, theOrders[i]->getOrderNumber());
		}
		if(haveElec){
			//ElectronicItems
			cout << "---------------" << endl;
			cout << setw(20) << "Elec. Items Ordered:" << setw(20) << "Item Number" << setw(40) << "Item Description" << setw(20) << "Warranty" << setw(10) << "Cost" << endl;
			cout << setw(20) << "                    " << setw(20) << "-----------" << setw(40) << "----------------" << setw(20) << "--------" << setw(10) << "----" << endl;
			printElectronics(tempVect, theOrders[i]->getOrderNumber());
		}
//		else{
//			cout << "Cheese it!" << endl;
//		}
		//Total
		cout << endl;
		cout << "The total for this order will be: $" << theOrders[i]->getTotalOfOrder() << endl;
		cout << endl;
	}
	cout << endl;
	cout << "Program ending, Have a nice day!" << endl; // prints Program ending, Have a nice day!
//	// DumbPointers?
//	theCustomers.clear();
//	theOrders.clear();


	return 0;
}

void printFood(vector<OrderItem*> ordPtr, string tempStr){
//	cout << ordPtr.size() << endl;
	//FoodItem *tempFoodI = new FoodItem();
	//tempFoodI =	dynamic_cast<FoodItem*>(ordPtr[0]->getItemNumber());
	for (unsigned int i = 0; i < ordPtr.size(); i++){
		if(ordPtr[i]->getOrderNumber() != tempStr || ordPtr[i]->whoAmI() != "FoodItem"){
			continue;
		}
		else if(ordPtr[i]->getOrderNumber() == tempStr && ordPtr[i]->whoAmI() == "FoodItem"){
			cout << setw(20) << " " << setw(20) << dynamic_cast<FoodItem*>(ordPtr[i])->getItemNumber()
				<< setw(40) << dynamic_cast<FoodItem*>(ordPtr[i])->getItemDescription()
				<< setw(20) << dynamic_cast<FoodItem*>(ordPtr[i])->getCalories()
				<< setw(10) << dynamic_cast<FoodItem*>(ordPtr[i])->getCustomerCost() << endl;
		}
		else{
			cout << "Something went wrong in the print food function" << endl;
		}
	}
}

void printMedia(vector<OrderItem*> ordPtr, string tempStr){
//	cout << ordPtr.size() << endl;
	for (unsigned int i = 0; i < ordPtr.size(); i++){
		if(ordPtr[i]->getOrderNumber() != tempStr || ordPtr[i]->whoAmI() != "MediaItem"){
			continue;
		}
		else if(ordPtr[i]->getOrderNumber() == tempStr && ordPtr[i]->whoAmI() == "MediaItem"){
			cout << setw(20) << " " << setw(20) << dynamic_cast<MediaItem*>(ordPtr[i])->getItemNumber()
				<< setw(40) << dynamic_cast<MediaItem*>(ordPtr[i])->getItemDescription()
				<< setw(20) << dynamic_cast<MediaItem*>(ordPtr[i])->getISBNNumber()
				<< setw(10) << dynamic_cast<MediaItem*>(ordPtr[i])->getCustomerCost() << endl;
		}
		else{
			cout << "Something went wrong in the print media function" << endl;
		}
	}
}

void printElectronics(vector<OrderItem*> ordPtr, string tempStr){
//	cout << ordPtr.size() << endl;
	for (unsigned int i = 0; i < ordPtr.size(); i++){
		if(ordPtr[i]->getOrderNumber() != tempStr || ordPtr[i]->whoAmI() != "ElectronicItem"){
			continue;
		}
		else if(ordPtr[i]->getOrderNumber() == tempStr && ordPtr[i]->whoAmI() == "ElectronicItem"){
			cout << setw(20) << " " << setw(20) << dynamic_cast<ElectronicItem*>(ordPtr[i])->getItemNumber()
				<< setw(40) << dynamic_cast<ElectronicItem*>(ordPtr[i])->getItemDescription()
				<< setw(20) << dynamic_cast<ElectronicItem*>(ordPtr[i])->getWarrantyMonths()
				<< setw(10) << dynamic_cast<ElectronicItem*>(ordPtr[i])->getCustomerCost() << endl;
		}
		else{
			cout << "Something went wrong in the print Electronics function" << endl;
		}
	}
}
