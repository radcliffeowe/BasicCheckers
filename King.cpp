/*
 * King.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#include "King.h"

King::King()
:black(0), spaceType(2){
	// TODO Auto-generated constructor stub

}

King::~King() {
	// TODO Auto-generated destructor stub
}

int King::getSpaceType()
{
	return this->spaceType;
}
void King::setBlack()
{
	this->black = true;
}

bool King::getBlack()
{
	return this->black;
}



