/*
 * ElectronicItem.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#include "ElectronicItem.hpp"

ElectronicItem::ElectronicItem() {
	// TODO Auto-generated constructor stub
	type = static_cast<Type>(0);
	warrantyMonths = 0;
}

ElectronicItem::~ElectronicItem() {
	// TODO Auto-generated destructor stub
}

string ElectronicItem::whoAmI(void){
	return "ElectronicItem";
	//this might not be what he wants....
}
Type ElectronicItem::getType(void){
	return type;
}
int ElectronicItem::getWarrantyMonths(void){
	return warrantyMonths;
}
void ElectronicItem::setType(int tempType){
	type = static_cast<Type>(tempType);
}
void ElectronicItem::setWarrantyMonths(int tempWar){
	warrantyMonths = tempWar;
}
