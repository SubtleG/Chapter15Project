/*
 * Order.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#include "Order.hpp"
#include <fstream>
using namespace std;

Order::Order() {
	// TODO Auto-generated constructor stub
	readFoodItems();
	readMediaItems();
	readElectronicItems();
}

Order::~Order() {
	// TODO Auto-generated destructor stub
}

void Order::readFoodItems(){
	ifstream foodFile;
	foodFile.open("FoodItems.txt");
		//foodFile >>
	foodFile.close();
}
void Order::readMediaItems(){
	ifstream mediaFile;
	mediaFile.open("MediaItems.txt");

	mediaFile.close();
}
void Order::readElectronicItems(){
	ifstream ElectronicFile;
	ElectronicFile.open("ElectronicItems.txt");

	ElectronicFile.close();
}
double Order::getTotalOfOrder(){
	double tot = 0.0;
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
