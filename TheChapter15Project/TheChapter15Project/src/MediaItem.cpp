/*
 * MediaItem.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: BryceX1
 */

#include "MediaItem.hpp"

MediaItem::MediaItem() {
	// TODO Auto-generated constructor stub

}

MediaItem::~MediaItem() {
	// TODO Auto-generated destructor stub
}

string MediaItem::whoAmI(void){
	return "MediaItem";
	//this might not be what he wants....
}
string MediaItem::getAuthorName(void){
	return authorName;
}
Date MediaItem::getPublicationDate(void){
	return publicationDate;
}
string MediaItem::getISBNNumber(void){
	return ISBNNumber;
}
void MediaItem::setAuthorName(string tempAuthName){
	authorName = tempAuthName;
}
void MediaItem::setPublicationDate(Date tempPubDate){
	publicationDate = tempPubDate;
}
void MediaItem::setISBNNumber(string tempISBNNum){
	ISBNNumber = tempISBNNum;
}
