/*
 * MediaItem.hpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#ifndef MEDIAITEM_HPP_
#define MEDIAITEM_HPP_

#include "OrderItem.hpp"
#include "Date.hpp"
#include <string>
using namespace std;

class MediaItem: public virtual OrderItem {
public:
	MediaItem();
	virtual ~MediaItem();

	virtual string whoAmI(void);

	string getAuthorName(void);
	Date getPublicationDate(void);
	string getISBNNumber(void);
	void setAuthorName(string);
	void setPublicationDate(Date);
	void setISBNNumber(string);

private:
	string authorName;
	Date publicationDate;
	string ISBNNumber;

};

#endif /* MEDIAITEM_HPP_ */
