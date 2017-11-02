/*
 * FoodItem.hpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#ifndef FOODITEM_HPP_
#define FOODITEM_HPP_

#include "OrderItem.hpp"
#include "Date.hpp"

class FoodItem: public virtual OrderItem {
public:
	FoodItem();
	virtual ~FoodItem();

	virtual string whoAmI(void);

	Date getExpirationDate(void);
	int getCalories(void);
	int getFat(void);
	void setExpirationDate(Date);
	void setCalories(int);
	void setFat(int);

private:
	Date expirationDate;
	int calories;
	int fat;

};

#endif /* FOODITEM_HPP_ */
