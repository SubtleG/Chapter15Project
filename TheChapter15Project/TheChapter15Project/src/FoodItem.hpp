/*
 * FoodItem.hpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#ifndef FOODITEM_HPP_
#define FOODITEM_HPP_

#include "OrderItem.hpp"

class FoodItem: public virtual OrderItem {
public:
	FoodItem();
	virtual ~FoodItem();
};

#endif /* FOODITEM_HPP_ */
