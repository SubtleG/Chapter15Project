/*
 * Order.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#include "Order.hpp"
#include <fstream>
#include <iostream>
using namespace std;

Order::Order() {
	// TODO Auto-generated constructor stub
	bool readError = false;
	readError = readFoodItems();
	if (readError){
		this->orderCustomer = nullptr;
		orderNumber = "Failed to open file";
	}
	readError = readMediaItems();
	if (readError){
		this->orderCustomer = nullptr;
		orderNumber = "Failed to open file";
	}
	readError = readElectronicItems();
	if (readError){
		this->orderCustomer = nullptr;
		orderNumber = "Failed to open file";
	}
}
Order::Order(vector<shared_ptr<Customer>> tempPoint, string custID, string orderNum){
	//if cust exists read files
	bool exists = true;
	for(unsigned int i = 0;  i < tempPoint.size(); i++){
		if (tempPoint[i].get()->getCustomerNumber() == custID){
			//this->orderCustomer = tempPoint->at(i);
			this->orderCustomer = tempPoint[i].get();
			this->orderNumber = orderNum;
			exists = true;
			break;
		}
		else{
			exists = false;
		}
	}
	if(exists){
		bool readError = false;
//		// prints the customer that was found
//		cout << "The customer " << custID << " was found." << endl;
		readError = readFoodItems();
		if (readError){
			this->orderCustomer = nullptr;
			orderNumber = "Failed to open file";
		}
		readError = readMediaItems();
		if (readError){
			this->orderCustomer = nullptr;
			orderNumber = "Failed to open file";
		}
		readError = readElectronicItems();
		if (readError){
			this->orderCustomer = nullptr;
			orderNumber = "Failed to open file";
		}
	}
	else{
		this->orderCustomer = nullptr;
		cout << "The customer " << custID << " was not found." << endl;
		orderNumber = "FAILFAILFAIL";
	}
}
Order::~Order() {
	// TODO Auto-generated destructor stub
	//itemsInOrder.clear();
	//for loop?
}

bool Order::readFoodItems(){

	try{
		ifstream foodFile;
		foodFile.open("FoodItems.txt");
		if (foodFile.fail()){
//			cout << "Error opening food file " << endl;
			throw "fooditems error";
		}
		else{
			while(!(foodFile.eof())){
				string ordNum, itemNum, itemDesc, taxEx, calories, fat;
				int quantity, expYear, expMonth, expDay;
				double price, cost;
				foodFile >> ordNum >>itemNum >> itemDesc >> quantity >> price \
				>> cost >> taxEx >> expYear >> expMonth >> expDay >> calories >> fat;
				if(ordNum != orderNumber){
					continue;
				}
				else{
					FoodItem *tempFoodItem = new FoodItem();
					tempFoodItem->setOrderNumber(ordNum);
					tempFoodItem->setItemNumber(itemNum);
					tempFoodItem->setItemDescription(itemDesc);
	//				int iquant = stoi(quantity);
	//				double dCost = stod(cost);
	//				double dPrice = stod(price);
					tempFoodItem->setQuantity(quantity);
					tempFoodItem->setCustomerCost(price);
					tempFoodItem->setVendorCost(cost);
					bool taxed;
					if(taxEx == "Y" || taxEx == "y"){
						taxed = true;
					}
					else if(taxEx == "N" || taxEx == "n"){
						taxed = false;
					}
					else{
						cout << "Tax exemption error, please bribe your representatives." << endl;
					}
					tempFoodItem->setTaxExempt(taxed);
	//				int intYear = stoi(expYear);
	//				int intMonth = stoi(expMonth);
	//				int intDay = stoi(expDay);
					Date expDate(expDay, expMonth, expYear);
					tempFoodItem->setExpirationDate(expDate);
					int intCal = stoi(calories);
					tempFoodItem->setCalories(intCal);
					int intFat = stoi(fat);
					tempFoodItem->setFat(intFat);
					itemsInOrder.push_back(tempFoodItem);
				}
			}
			foodFile.close();
		}
	}//try
	catch(...){
		cout << "There was an error reading food items." << endl;
		return true;
	}//catch
	return false;
}
bool Order::readMediaItems(){

	try{
		ifstream mediaFile;
		mediaFile.open("MediaItems.txt");
		if (mediaFile.fail()){
//			cout << "Error opening media file " << endl;
			throw "mediaitems error";
		}
		else{
			while(!(mediaFile.eof())){
				string ordNum, itemNum, itemDesc, taxEx, author, ISBN;
				int quantity, pubYear, pubMonth, pubDay;
				double price, cost;
				mediaFile >> ordNum >>itemNum >> itemDesc >> quantity >> price
				>> cost >> taxEx >> pubYear >> pubMonth >> pubDay >> author >> ISBN;
				if(ordNum != orderNumber){
					continue;
				}
				else{
					MediaItem *tempMediaItem = new MediaItem();
					tempMediaItem->setOrderNumber(ordNum);
					tempMediaItem->setItemNumber(itemNum);
					tempMediaItem->setItemDescription(itemDesc);
	//				int iquant = stoi(quantity);
	//				double dCost = stod(cost);
	//				double dPrice = stod(price);
					tempMediaItem->setQuantity(quantity);
					tempMediaItem->setCustomerCost(price);

					tempMediaItem->setVendorCost(cost);
					bool taxed;
					if(taxEx == "Y" || taxEx == "y"){
						taxed = true;
					}
					else if(taxEx == "N" || taxEx == "n"){
						taxed = false;
					}
					else{
						cout << "Tax exemption error, please bribe your representatives." << endl;
					}
					tempMediaItem->setTaxExempt(taxed);
	//				int intYear = stoi(pubYear);
	//				int intMonth = stoi(pubMonth);
	//				int intDay = stoi(pubDay);
					Date pubDate(pubDay, pubMonth, pubYear);
					tempMediaItem->setPublicationDate(pubDate);
					tempMediaItem->setAuthorName(author);
					tempMediaItem->setISBNNumber(ISBN);
					itemsInOrder.push_back(tempMediaItem);
				}
			}
			mediaFile.close();
		}
	}//try
	catch(...){
		cout << "There was an error reading media items." << endl;
		return true;
	}//catch
	return false;
}
bool Order::readElectronicItems(){

	try{
		ifstream ElectronicFile;
		ElectronicFile.open("ElectronicItems.txt");
		if (ElectronicFile.fail()){
//			cout << "Error opening electronic file " << endl;
			throw "electronics error";
		}
		else{
			while(!(ElectronicFile.eof())){
				string ordNum, itemNum, itemDesc, taxEx, type;
				int quantity, warrMonths;
				double price, cost;
				ElectronicFile >> ordNum >>itemNum >> itemDesc >> quantity >> price
				>> cost >> taxEx >> type >> warrMonths;
				if(ordNum != orderNumber){
					continue;
				}
				else{
					ElectronicItem *tempElectronicItem = new ElectronicItem();
					tempElectronicItem->setOrderNumber(ordNum);
					tempElectronicItem->setItemNumber(itemNum);
					tempElectronicItem->setItemDescription(itemDesc);
	//				int iquant = stoi(quantity);
	//				double dCost = stod(cost);
	//				double dPrice = stod(price);
					tempElectronicItem->setQuantity(quantity);
					tempElectronicItem->setCustomerCost(price);
					tempElectronicItem->setVendorCost(cost);
					bool taxed;
					if(taxEx == "Y" || taxEx == "y"){
						taxed = true;
					}
					else if(taxEx == "N" || taxEx == "n"){
						taxed = false;
					}
					else{
						cout << "Tax exemption error, please bribe your representatives." << endl;
					}
					tempElectronicItem->setTaxExempt(taxed);
					int intType = stoi(type);
					tempElectronicItem->setType(intType);
					tempElectronicItem->setWarrantyMonths(warrMonths);
					itemsInOrder.push_back(tempElectronicItem);
				}
			}
			ElectronicFile.close();
		}
	}//try
	catch(...){
		cout << "There was an error reading electronics items." << endl;
		return true;
	}//catch
	return false;
}
double Order::getTotalOfOrder(){
	double tot = 0.0;
	for(unsigned int i = 0; i < this->itemsInOrder.size(); i++){
		tot += (itemsInOrder[i]->getCustomerCost()*itemsInOrder[i]->getQuantity());
	}
	return tot;
}
string Order::getOrderNumber(void){
	return orderNumber;
}
Date Order::getOrderDate(void){
	return orderDate;
}
vector<OrderItem*> Order::getItemsInOrder(void){
	return itemsInOrder;
}
Customer Order::getOrderCustomer(void){
	return *orderCustomer;
}
void Order::setOrderNumber(string tempOrNum){
	orderNumber = tempOrNum;
}
void Order::setOrderDate(Date tempDate){
	orderDate = tempDate;
}
void Order::setItemsInOrder(vector<OrderItem*> tempVect){
	itemsInOrder = tempVect;
}
void Order::setOrderCustomer(Customer tempCust){
	*orderCustomer = tempCust;
}
