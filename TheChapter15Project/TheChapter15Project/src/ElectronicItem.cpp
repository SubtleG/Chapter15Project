/*
 * ElectronicItem.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#include "ElectronicItem.hpp"

ElectronicItem::ElectronicItem() {
	// TODO Auto-generated constructor stub

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
void ElectronicItem::setType(Type tempType){
	type = tempType;
}
void ElectronicItem::setWarrantyMonths(int tempWar){
	warrantyMonths = tempWar;
}
