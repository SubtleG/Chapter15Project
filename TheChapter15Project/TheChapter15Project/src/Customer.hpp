/*
 * Customer.hpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_
#include "Date.hpp"
#include <string>
using namespace std;

class Customer {
public:
	Customer();
	virtual ~Customer();

	string getCustomerNumber(void);
	string getCustomerName(void);
	string getEmail(void);
	Date getDateJoined(void);
	void setCustomerNumber(string);
	void setCustomerName(string);
	void setEmail(string);
	void setDateJoined(Date);

private:
	string customerNumber;
	string customerName;
	string email;
	Date dateJoined;
};

#endif /* CUSTOMER_HPP_ */
