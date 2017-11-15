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
#include "Order.hpp"
#include "OrderItem.hpp"
#include "FoodItem.hpp"
#include "Date.hpp"
#include "Customer.hpp"
using namespace std;

//bool readCustomers(string, vector<Customer*>);
//bool readOrders(string);

int main() {

	//#1
	vector<Customer*> theCustomers;
	Customer *tempCust = new Customer();

	//#2
//	newCust.setCustomerName("steve");
//	newCust.setCustomerNumber("cust007");
//	newCust.setEmail("guesswho@gmail.com");
//
//	cout << newCust.getCustomerName() << endl;
//	cout << newCust.getCustomerNumber() << endl;
//	cout << newCust.getEmail() << endl;
//	theCustomers.push_back(&newCust);
//
//	cout << theCustomers[0]->getCustomerName() << endl;
//	cout << theCustomers[0]->getCustomerNumber() << endl;
//	cout << theCustomers[0]->getEmail() << endl;
//	string testStr = "123456789";
//	int testInt = stoi(testStr);
//	cout << testInt << endl;

	ifstream custFile;
	if (custFile.fail()){
		cout << "Error opening file " << endl;
	}
	else{
		//can start a while !eof loop
		custFile.open("CustomerFile.txt");
		string custNum, custName, custEmail, year, month, day;
		custFile >> custNum >> custName >> custEmail >> year >> month >> day;
//		custFile >> custNum;
//		custFile >> custName;
//		custFile >> custEmail;
//		custFile >> year;
//		custFile >> month;
//		custFile >> day;
		Customer *custNum1 = new Customer;
		custNum1->setCustomerNumber(custNum);
		custNum1->setCustomerName(custName);
    	custNum1->setEmail(custEmail);
    	int iYear = stoi(year);
    	int iMonth = stoi(month);
    	int iDay = stoi(day);
    	Date custJoin(iDay, iMonth, iYear);
    	custNum1->setDateJoined(custJoin);
    	theCustomers.push_back(custNum1);
//		cout << custNum1.getCustomerName() << endl;
//		cout << custNum1.getCustomerNumber() << endl;
//		cout << custNum1.getEmail() << endl;
//
//		cout << theCustomers[0]->getCustomerName() << endl;
//		cout << theCustomers[0]->getCustomerNumber() << endl;
//		cout << theCustomers[0]->getEmail() << endl;
//
// 		cout << theCustomers[0]->getDateJoinedString() << endl;
    	custFile.close();
	}

	tempCust = nullptr;
	delete []tempCust;

	//#3
	vector<Order*> theOrders;
	Order *tempOrder = new Order();

	//#4
	ifstream orderFile;
	if (orderFile.fail()){
		cout << "Error opening file " << endl;
	}
	else{

		orderFile.open("OrderFile.txt");
		string ordID, ordYear, ordMonth, ordDay, custNum;
		orderFile >> ordID >> ordYear >> ordMonth >> ordDay >> custNum;
		// can check for existing customer with custNum to see if they exist

		Order ordNum1(theCustomers, custNum);
		ordNum1.setOrderNumber(ordID);
    	int iYear = stoi(ordYear);
    	int iMonth = stoi(ordMonth);
    	int iDay = stoi(ordDay);
    	Date ordDate(iDay, iMonth, iYear);
		ordNum1.setOrderDate(ordDate);
    	theOrders.push_back(&ordNum1);

    	orderFile.close();
	}
	tempOrder = nullptr;
	delete []tempOrder;

	//#5
	//Prints out the order report
	cout << "Order Report:" << endl;

	for(unsigned int i = 0; i < theOrders.size(); i++){
		cout << "==============================" << endl;
		cout << setw(15) << "Order ID" << setw(20) << "Customer ID" << setw(20) << "Order Date" << setw(40) << "Customer" << endl;
		cout << setw(15) << "--------" << setw(20) << "-----------" << setw(20) << "----------" << setw(40) << "--------" << endl;
		cout << setw(15) << theOrders[i]->getOrderNumber() << setw(20) << theOrders[i]->getOrderCustomer().getCustomerNumber() << setw(20) << theOrders[i]->getOrderDate().getDateString()\
			<< setw(40) << theOrders[i]->getOrderCustomer().getCustomerName() << endl;
		//FoodItems
		cout << "---------------" << endl;
		cout << setw(20) << "Food Items Ordered:" << setw(20) << "Item Number" << setw(40) << "Item Description" << setw(20) << "Calories" << setw(20) << "Cost" << endl;
		cout << setw(20) << "-------------------" << setw(20) << "-----------" << setw(40) << "----------------" << setw(20) << "--------" << setw(20) << "----" << endl;
		//cout << setw(20) << "-------------------" << setw(20) << static_cast<FoodItem*>(theOrders[i])->getItemNumber() << setw(40) << dynamic_cast<FoodItem*>(theOrders[i])->getItemDescription() << setw(20) << dynamic_cast<FoodItem*>(theOrders[i])->getCalories() << setw(20) << dynamic_cast<FoodItem*>(theOrders[i])->getCustomerCost() << endl;


	}


	cout << endl;
	cout << endl;
	cout << "Program ending, Have a nice day!" << endl; // prints Program ending, Have a nice day!
	return 0;
}
//
//bool readCustomers(string fileName, vector<Customer*> vectPointer){
//
//	string custNum;
//	string custName;
//	string custEmail;
//	//Date custDateJoin;
//	string year;
//	string month;
//	string day;
//	ifstream custFile(fileName);
//	  if (custFile.is_open())
//	  {
//	    custFile >> custNum >> custName >> custEmail >> year >> month >> day;
//
//	    vectPointer.push_back();
//	    custFile.close();
//	  }
//	  else{
//		  cout << "Error opening file " << fileName << endl;
//	  }
//
//	return true;
//}
//
//bool readOrders(string fileName){
//	string orderNum;
//	//Date custDateJoin;
//	string year;
//	string month;
//	string day;
//	string custNum;
//	ifstream custFile(fileName);
//	  if (custFile.is_open())
//	  {
//	    custFile >> orderNum >> year >> month >> day >> custNum;
//	    custFile.close();
//	  }
//	  else{
//		  cout << "Error opening file " << fileName << endl;
//	  }
//
//	return true;
//}
//
