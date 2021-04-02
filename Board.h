/*
 * Board.h
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Space.h"
#include "Pawn.h"
#include "King.h"
#include "Empty.h"
#include "LLMove.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define FILENAMELENGTHALLOWANCE 50

class Board {
public:
	Board();
	virtual ~Board();
	void setCorner(Space**);
	Space** getCorner();
	void initStd();
	void initFile(const char* filename);
	void displayBoard();
	Space* crown(Space* piece);
	LLMove* checkMove(Space* piece);
	void move(moveInfo*);
	void recordMove(moveInfo*, int, const char*);
	bool checkWin();
private:
	int size = 8;
	Space** corner;
};

#endif /* BOARD_H_ */
