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
	readFoodItems();
	readMediaItems();
	readElectronicItems();
}
Order::Order(vector<Customer*> tempPoint, string custID, string orderNum){
	//if cust exists read files
	bool exists = true;
	for(unsigned int i = 0;  i < tempPoint.size(); i++){
		if (tempPoint[i]->getCustomerNumber() == custID){
			orderCustomer = tempPoint[i];
			orderNumber = orderNum;
			exists = true;
			break;
		}
		else{
			exists = false;
		}
	}
	if(exists){
		cout << "The customer " << custID << " was found." << endl;
		readFoodItems();
		readMediaItems();
		readElectronicItems();
	}
	else{
		orderCustomer = nullptr;
		cout << "The customer " << custID << " was not found." << endl;
	}
}
Order::~Order() {
	// TODO Auto-generated destructor stub
}

void Order::readFoodItems(){
	ifstream foodFile;
	if (foodFile.fail()){
		cout << "Error opening file " << endl;
	}
	else{
		foodFile.open("FoodItems.txt");
		while(!(foodFile.eof())){
			string ordNum, itemNum, itemDesc, quantity, price, cost,\
			taxEx, expYear, expMonth, expDay, calories, fat;
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
				int iquant = stoi(quantity);
				tempFoodItem->setQuantity(iquant);
				double dPrice = stod(price);
				tempFoodItem->setCustomerCost(dPrice);
				double dCost = stod(cost);
				tempFoodItem->setVendorCost(dCost);
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
				int intYear = stoi(expYear);
				int intMonth = stoi(expMonth);
				int intDay = stoi(expDay);
				Date expDate(intDay, intMonth, intYear);
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
}
void Order::readMediaItems(){
	ifstream mediaFile;
	if (mediaFile.fail()){
		cout << "Error opening file " << endl;
	}
	else{
		mediaFile.open("MediaItems.txt");
		while(!(mediaFile.eof())){
			string ordNum, itemNum, itemDesc, quantity, price, cost,\
			taxEx, pubYear, pubMonth, pubDay, author, ISBN;
			mediaFile >> ordNum >>itemNum >> itemDesc >> quantity >> price \
			>> cost >> taxEx >> pubYear >> pubMonth >> pubDay >> author >> ISBN;
			if(ordNum != orderNumber){
				continue;
			}
			else{
				MediaItem *tempMediaItem = new MediaItem();
				tempMediaItem->setOrderNumber(ordNum);
				tempMediaItem->setItemNumber(itemNum);
				tempMediaItem->setItemDescription(itemDesc);
				int iquant = stoi(quantity);
				tempMediaItem->setQuantity(iquant);
				double dPrice = stod(price);
				tempMediaItem->setCustomerCost(dPrice);
				double dCost = stod(cost);
				tempMediaItem->setVendorCost(dCost);
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
				int intYear = stoi(pubYear);
				int intMonth = stoi(pubMonth);
				int intDay = stoi(pubDay);
				Date pubDate(intDay, intMonth, intYear);
				tempMediaItem->setPublicationDate(pubDate);
				tempMediaItem->setAuthorName(author);
				tempMediaItem->setISBNNumber(ISBN);
				itemsInOrder.push_back(tempMediaItem);
			}
		}
    	mediaFile.close();
	}
}
void Order::readElectronicItems(){
	ifstream ElectronicFile;
	if (ElectronicFile.fail()){
		cout << "Error opening file " << endl;
	}
	else{
		ElectronicFile.open("ElectronicItems.txt");
		while(!(ElectronicFile.eof())){
			string ordNum, itemNum, itemDesc, quantity, price, cost,\
			taxEx, type, warrMonths;
			ElectronicFile >> ordNum >>itemNum >> itemDesc >> quantity >> price \
			>> cost >> taxEx >> type >> warrMonths;
			if(ordNum != orderNumber){
				continue;
			}
			else{
				ElectronicItem *tempElectronicItem = new ElectronicItem();
				tempElectronicItem->setOrderNumber(ordNum);
				tempElectronicItem->setItemNumber(itemNum);
				tempElectronicItem->setItemDescription(itemDesc);
				int iquant = stoi(quantity);
				tempElectronicItem->setQuantity(iquant);
				double dPrice = stod(price);
				tempElectronicItem->setCustomerCost(dPrice);
				double dCost = stod(cost);
				tempElectronicItem->setVendorCost(dCost);
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
				itemsInOrder.push_back(tempElectronicItem);
			}
		}
		ElectronicFile.close();
	}
}
double Order::getTotalOfOrder(){
	double tot = 0.0;
	for(unsigned int i = 0; i < this->itemsInOrder.size(); i++){
		tot += (itemsInOrder[i]->getCustomerCost()*itemsInOrder[i]->getQuantity());
	}
	return tot;
	//When I Debugged this it added both foodtext items, then skipped mediaitems, then added 1 item from elec. items before exiting.
	//no matter which order called it.
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
