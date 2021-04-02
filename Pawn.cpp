/*
 * Pawn.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#include "Pawn.h"

Pawn::Pawn()
: black(0), spaceType(1){
	// TODO Auto-generated constructor stub

}

Pawn::~Pawn() {
	// TODO Auto-generated destructor stub
}

int Pawn::getSpaceType()
{
	return this->spaceType;
}

void Pawn::setBlack()
{
	this->black = true;
}

bool Pawn::getBlack()
{
	return this->black;
}


/*
King* Pawn::crown()
{
	Pawn* pw = (Pawn*)malloc(sizeof(Pawn));
	int col = pw->getCol();
	int row = pw->getRow();
	bool team = pw->getBlack();
	if(team)
	{
		pw = new King();
		pw->setCol(col);
		pw->setRow(row);
		pw->setBlack();
	}
	else
	{
		pw = new King();
		pw->setCol(col);
		pw->setRow(row);
	}
	return pw;
}
*/













