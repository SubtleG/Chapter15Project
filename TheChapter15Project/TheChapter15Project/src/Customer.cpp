/*
 * Customer.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#include "Customer.hpp"
#include <iostream>


Customer::Customer() {
	// TODO Auto-generated constructor stub
	//cout << "You are creating a customer" << endl;
	customerNumber = "unknown";
	customerName  = "unknown";
	email  = "unknown";
	//dateJoined = ;
}

Customer::~Customer() {
	// TODO Auto-generated destructor stub
	//cout << "You are destroying a customer" << endl;
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
string Customer::getDateJoinedString(void){
	string joinDate;
	joinDate = (this->dateJoined.getDateString());
	return joinDate;
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
