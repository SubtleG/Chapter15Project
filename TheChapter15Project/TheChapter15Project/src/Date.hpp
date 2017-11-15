/*
 * Date.hpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#ifndef DATE_HPP_
#define DATE_HPP_
#include <string>

class Date {
public:
	Date();
	virtual ~Date();

	Date(int, int, int);

	std::string getDateString(void);

	int year;
	int month;
	int day;


};

#endif /* DATE_HPP_ */
