/*
 * King.h
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#ifndef KING_H_
#define KING_H_

#include "Pawn.h"

class King: public Pawn {
public:
	King();
	virtual ~King();
	void setBlack();
	bool getBlack();
	int getSpaceType();
private:
	bool black;
	int spaceType;
};

#endif /* KING_H_ */
