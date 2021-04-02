/*
 * LLMove.cpp
 *
 *  Created on: Mar 5, 2021
 *      Author: radcl
 */

#include "LLMove.h"

LLMove::LLMove()
:prev((LLMove*)0), next((LLMove*)0), move((moveInfo*)0){
	// TODO Auto-generated constructor stub

}

LLMove::~LLMove() {
	// TODO Auto-generated destructor stub
}

void LLMove::setNext(LLMove* lp)
{
	this->next = lp;
}

LLMove* LLMove::getNext()
{
	return this->next;
}

void LLMove::setPrev(LLMove* lp)
{
	this->prev = lp;
}

LLMove* LLMove::getPrev()
{
	return this->prev;
}

void LLMove::setMove(moveInfo* mp)
{
	this->move = mp;
}

moveInfo* LLMove::getMove()
{
	return this->move;
}

bool LLMove::isEmpty()
{
	bool empty = false;
	if(this->move == (moveInfo*)0)
	{
		empty = true;
	}
	return empty;
}

void LLMove::saveMove(moveInfo* mp)
{
	if(this->isEmpty())
	{
		this->move = mp;
	}
	else
	{
		LLMove* temp = this;
		while(temp->next)
		{
			temp = temp->next;
		}
		LLMove* newMove = new LLMove();
		newMove->move = mp;
		temp->next = newMove;
		newMove->prev = temp;
	}
}

moveInfo* LLMove::selectMove()
{
	moveInfo* currBest = (moveInfo*)malloc(sizeof(moveInfo));
	currBest->jump = false;
	currBest->valid = false;
	if(this->isEmpty())
	{
		perror("no possible moves");fflush(stderr);
	}
	else
	{
		cout<<"selecting a move..."<<endl;
		LLMove* temp = this;
		bool done = false;
		while((!done) && temp->next)
		{
			moveInfo* tempMove = temp->move;
			if(tempMove->jump)
			{
				currBest = tempMove;
				done = true;
			}
			else
			{
				currBest = tempMove;
			}
			temp = temp->next;
		}
		//either pointing at last possible move, or found a jump
		if(!currBest->jump) //move is not a jump
		{
			moveInfo* tempMove = temp->move;
			if(tempMove->jump)
			{
				currBest = tempMove;
			}
			else
			{
				currBest = tempMove;
			}
		}
		cout<<"move selected"<<endl;
	}
	return currBest;
}









