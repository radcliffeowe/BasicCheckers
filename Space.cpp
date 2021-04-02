/*
 * Space.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#include "Space.h"

Space::Space(){
	// TODO Auto-generated constructor stub

}

Space::~Space() {
	// TODO Auto-generated destructor stub
}

void Space::setDark()
{
	this->dark = true;
}

bool Space::getDark()
{
	return this->dark;
}

void Space::setCol(int col)
{
	this->col = col;
}

int Space::getCol()
{
	return this->col;
}

void Space::setRow(int row)
{
	this->row = row;
}

int Space::getRow()
{
	return this->row;
}

void Space::setSpaceType(int type)
{
	this->spaceType = type;
}







