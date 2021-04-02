/*
 * LLMove.h
 *
 *  Created on: Mar 5, 2021
 *      Author: radcl
 */

#ifndef LLMOVE_H_
#define LLMOVE_H_

#include "Space.h"
#include "Pawn.h"
#include "King.h"
#include <errno.h>
#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct
{
	bool valid;
	int newCol;
	int newRow;
	bool jump;
	Space* jumped;
	Space* piece;
}moveInfo;

class LLMove {
public:
	LLMove();
	virtual ~LLMove();
	void saveMove(moveInfo* mp);
	bool isEmpty();
	moveInfo* selectMove();
	void setNext(LLMove*);
	LLMove* getNext();
	void setPrev(LLMove*);
	LLMove* getPrev();
	void setMove(moveInfo*);
	moveInfo* getMove();
private:
	LLMove* prev;
	moveInfo* move;
	LLMove* next;
};

#endif /* LLMOVE_H_ */
