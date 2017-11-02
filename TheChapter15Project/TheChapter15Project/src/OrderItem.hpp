/*
 * OrderItem.hpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#ifndef ORDERITEM_HPP_
#define ORDERITEM_HPP_
#include <string>
using namespace std;

class OrderItem {
public:
	OrderItem();
	virtual ~OrderItem();



	string getOrderNumber(void);
	string getItemNumber(void);
	string getItemDescription(void);
	int getQuantity(void);
	double getCustomerCost(void);
	double getVendorCost(void);
	bool getTaxExempt(void);
	void setOrderNumber(string);
	void setItemNumber(string);
	void setItemDescription(string);
	void setQuantity(int);
	void setCustomerCost(double);
	void setVendorCost(double);
	void setTaxExempt(bool);


private:
	string orderNumber;
	string itemNumber;
	string itemDescription;
	int quantity;
	double customerCost;
	double vendorCost;
	bool taxExempt;

};

#endif /* ORDERITEM_HPP_ */
