/*
 * Empty.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#include "Empty.h"

Empty::Empty()
:spaceType(0), dark(0), black(0){
	// TODO Auto-generated constructor stub

}

Empty::~Empty() {
	// TODO Auto-generated destructor stub
}

void Empty::setBlack()
{
}

bool Empty::getBlack()
{
	return this->black;
}

int Empty::getSpaceType()
{
	return this->spaceType;
}



