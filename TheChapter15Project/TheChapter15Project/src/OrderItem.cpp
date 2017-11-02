/*
 * OrderItem.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#include "OrderItem.hpp"

OrderItem::OrderItem() {
	// TODO Auto-generated constructor stub

}

OrderItem::~OrderItem() {
	// TODO Auto-generated destructor stub
}

string OrderItem::getOrderNumber(void){
	return orderNumber;
}
string OrderItem::getItemNumber(void){
	return itemNumber;
}
string OrderItem::getItemDescription(void){
	return itemDescription;
}
int OrderItem::getQuantity(void){
	return quantity;
}
double OrderItem::getCustomerCost(void){
	return customerCost;
}
double OrderItem::getVendorCost(void){
	return vendorCost;
}
bool OrderItem::getTaxExempt(void){
	return taxExempt;
}
void OrderItem::setOrderNumber(string tempONum){
	orderNumber = tempONum;
}
void OrderItem::setItemNumber(string tempINum){
	itemNumber = tempINum;
}
void OrderItem::setItemDescription(string tempIDesc){
	itemDescription = tempIDesc;
}
void OrderItem::setQuantity(int tempQuant){
	quantity = tempQuant;
}
void OrderItem::setCustomerCost(double tempCCost){
	customerCost = tempCCost;
}
void OrderItem::setVendorCost(double tempVCost){
	vendorCost = tempVCost;
}
void OrderItem::setTaxExempt(bool tempTax){
	taxExempt = tempTax;
}
