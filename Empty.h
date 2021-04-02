/*
 * Empty.h
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#ifndef EMPTY_H_
#define EMPTY_H_

#include "Space.h"

class Empty: public Space {
public:
	Empty();
	virtual ~Empty();
	void setBlack();
	bool getBlack();
	int getSpaceType();
private:
	int spaceType;
	bool dark;
	bool black;
};

#endif /* EMPTY_H_ */
