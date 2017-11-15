/*
 * Date.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#include "Date.hpp"

Date::Date() {
	// TODO Auto-generated constructor stub
	year = 0;
	month = 0;
	day = 0;
}

Date::~Date() {
	// TODO Auto-generated destructor stub
}
Date::Date(int tDay, int tMonth, int tYear){
	// Non-default constructor stub
	year = tYear;
	month = tMonth;
	day = tDay;
}
std::string Date::getDateString(void){
	std::string retDate;
	std::string sYear = std::to_string(this->year);
	std::string sMonth = std::to_string(this->month);
	std::string sDay = std::to_string(this->day);
	retDate = sMonth + "/" + sDay + "/" + sYear;
	return retDate;
}
