/*
 * Pawn.h
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#ifndef PAWN_H_
#define PAWN_H_

#include "Space.h"
#include <stdlib.h>

class Pawn: public Space {
public:
	Pawn();
	virtual ~Pawn();
	void setBlack();
	bool getBlack();
	int getSpaceType();
private:
	bool black;
	int spaceType;
};

#endif /* PAWN_H_ */
