/*
 * Order.hpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#ifndef ORDER_HPP_
#define ORDER_HPP_
#include "Date.hpp"
#include "OrderItem.hpp"
#include "FoodItem.hpp"
#include "ElectronicItem.hpp"
#include "MediaItem.hpp"
#include "Customer.hpp"
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Order {
public:
	Order();
	virtual ~Order();

	Order(vector<Customer*>*, string, string);

	bool readFoodItems();
	bool readMediaItems();
	bool readElectronicItems();
	double getTotalOfOrder();

	string getOrderNumber(void);
	Date getOrderDate(void);
	vector<OrderItem*> getItemsInOrder(void);
	Customer getOrderCustomer(void);
	void setOrderNumber(string);
	void setOrderDate(Date);
	void setItemsInOrder(vector<OrderItem*>);
	void setOrderCustomer(Customer);

private:
	string orderNumber;
	Date orderDate;
	vector<OrderItem*> itemsInOrder;
	Customer *orderCustomer;

};

#endif /* ORDER_HPP_ */
