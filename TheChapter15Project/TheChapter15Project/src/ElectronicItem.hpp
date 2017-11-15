/*
 * ElectronicItem.hpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#ifndef ELECTRONICITEM_HPP_
#define ELECTRONICITEM_HPP_

#include "OrderItem.hpp"

enum class Type{
	TV, PS4, DVDPlayer, Phone
};

class ElectronicItem: public virtual OrderItem {
public:
	ElectronicItem();
	virtual ~ElectronicItem();

	virtual string whoAmI(void);

	Type getType(void);
	int getWarrantyMonths(void);
	void setType(int);
	void setWarrantyMonths(int);

private:
	Type type;
	int warrantyMonths;

};

#endif /* ELECTRONICITEM_HPP_ */
