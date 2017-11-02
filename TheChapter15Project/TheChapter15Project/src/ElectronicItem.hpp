/*
 * ElectronicItem.hpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#ifndef ELECTRONICITEM_HPP_
#define ELECTRONICITEM_HPP_

#include "OrderItem.hpp"

class ElectronicItem: public virtual OrderItem {
public:
	ElectronicItem();
	virtual ~ElectronicItem();
};

#endif /* ELECTRONICITEM_HPP_ */
