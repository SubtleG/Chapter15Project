/*
 * Customer.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#include "Customer.hpp"

Customer::Customer() {
	// TODO Auto-generated constructor stub
	customerNumber = "unknown";
	customerName  = "unknown";
	email  = "unknown";
	//dateJoined = ;
}

Customer::~Customer() {
	// TODO Auto-generated destructor stub
}

string Customer::getCustomerNumber(void){
	return customerNumber;
}
string Customer::getCustomerName(void){
	return customerName;
}
string Customer::getEmail(void){
	return email;
}
Date Customer::getDateJoined(void){
	return dateJoined;
}
void Customer::setCustomerNumber(string tempNum){
	customerNumber = tempNum;
}
void Customer::setCustomerName(string tempName){
	customerName = tempName;
}
void Customer::setEmail(string tempEmail){
	email = tempEmail;
}
void Customer::setDateJoined(Date tempDate){
	dateJoined = tempDate;
}
