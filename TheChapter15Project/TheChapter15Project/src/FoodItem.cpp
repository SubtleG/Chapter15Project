/*
 * FoodItem.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#include "FoodItem.hpp"

FoodItem::FoodItem() {
	// TODO Auto-generated constructor stub

}

FoodItem::~FoodItem() {
	// TODO Auto-generated destructor stub
}

string FoodItem::whoAmI(void){
	return "FoodItem";
	//this might not be what he wants....
}
Date FoodItem::getExpirationDate(void){
	return expirationDate;
}
int FoodItem::getCalories(void){
	return calories;
}
int FoodItem::getFat(void){
	return fat;
}
void FoodItem::setExpirationDate(Date tempExpDate){
	expirationDate = tempExpDate;
}
void FoodItem::setCalories(int tempCalNum){
	calories = tempCalNum;
}
void FoodItem::setFat(int tempFatNum){
	fat = tempFatNum;
}
