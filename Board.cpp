/*
 * Board.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#include "Board.h"

Board::Board() {
	// TODO Auto-generated constructor stub

}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

void Board::setCorner(Space** newCorner)
{
	this->corner = newCorner;
}

Space** Board::getCorner()
{
	return this->corner;
}
void Board::initStd()
{
	for(int row = 0; row<8;row++)
	{
		for(int col = 0; col<8;col++)
		{
			Space* sq = (Space*)malloc(sizeof(Space));
			if(row>= 2 && row<=5)
			{
				if((row+col)%2 == 0)
				{
					sq = new Empty();
					sq->setDark();
				}
				else
				{
					sq = new Empty();
				}
			}
			if(row<2)
			{
				if((row+col)%2 ==0)
				{
					sq = new Pawn();
				}
				else
				{
					sq = new Empty();
				}
			}
			if(row>5)
			{
				if((row+col)%2 == 0)
				{
					sq = new Pawn();
					sq->setBlack();
				}
				else
				{
					sq = new Empty();
				}
			}
			sq->setCol(col);
			sq->setRow(row);
			Space** space = this->corner + row*8 + col;
			*space = sq;
		}
	}
}

void Board::initFile(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if(fp == NULL)
	{
		perror("Error! opening file");fflush(stderr);
	}
	else
	{
		int temp = -1;
		for(int row = 0; row<8; row++)
		{
			for(int col = 0; col<8; col++)
			{
				Space* x = (Space*)malloc(sizeof(Space));
				fscanf(fp, "%d", &temp);
				if(temp == 0)
				{
					if((row+col)%2 == 1)
					{
						x = new Empty();
						x->setDark();
					}
					else
					{
						x = new Empty();
					}
				}
				if(temp == 1)
				{
					x = new Pawn();
					x->setBlack();
					x->setDark();
				}
				if(temp == 2)
				{
					x = new King();
					x->setBlack();
					x->setDark();
				}
				if(temp == 3)
				{
					x = new Pawn();
					x->setDark();
				}
				if(temp == 4)
				{
					x = new King();
					x->setDark();
				}
				x->setCol(col);
				x->setRow(row);
				Space** spot = this->corner + row*8 + col;
				*spot = x;
			}
		}
	}
}

void Board::displayBoard()
{
	printf("     00  01  02  03  04  05  06  07 \n");fflush(stdout);
	for(int row = 0; row<8; row++)
	{
		printf(" %d |", row);fflush(stdout);
		for(int col = 0; col<8; col++)
		{
			Space* space = *(this->corner + row*8 +col);
			if(space->getSpaceType() == 0)
			{
					printf(" -- ");fflush(stdout);
			}
			else if(space->getSpaceType() == 1)
			{
				if(space->getBlack())
				{
					printf(" BP ");fflush(stdout);
				}
				else
				{
					printf(" RP ");fflush(stdout);
				}
			}
			else if(space->getSpaceType() == 2)
			{
				if(space->getBlack())
				{
					printf(" BK ");fflush(stdout);
				}
				else
				{
					printf(" RK ");fflush(stdout);
				}
			}
		}
		printf("|\n");fflush(stdout);
	}
}





Space* Board::crown(Space* piece)
{
	int col = piece->getCol();
	int row = piece->getRow();
	King* newPiece = new King();
	if(piece->getSpaceType() == 2 || piece->getSpaceType() == 0)
	{
		return piece;
	}
	if(piece->getSpaceType() == 1)
	{
		if(piece->getRow() == 0 && piece->getBlack())
		{
			bool team = piece->getBlack();
			if(team)
			{

				newPiece->setCol(col);
				newPiece->setRow(row);
				newPiece->setDark();
			}
		}
		else if(piece->getRow() == 7 && piece->getBlack() == false)
		{
			bool team = piece->getBlack();
			if(!team)
			{
				newPiece->setCol(col);
				newPiece->setRow(row);
			}
		}
	}
	Space** spot = this->corner + row*8 + col;
	*spot = newPiece;
	return newPiece;
}

LLMove* Board::checkMove(Space* piece)
{
	LLMove* moves = new LLMove();
	if(piece->getSpaceType() == 0) //empty spot
	{
		return moves;
	}
	else if((piece->getSpaceType() == 1 || piece->getSpaceType() == 2) && piece->getBlack())//black pawn
	{
		//check left up
		if(piece->getCol() > 0 && piece->getRow() > 0)
		{
			moveInfo* mp = (moveInfo*)malloc(sizeof(moveInfo));
			mp->piece = piece;
			Space* upLeft = *(this->corner + 8*piece->getRow() + piece->getCol() - 9);
			if(piece->getCol() >1 && piece->getCol() > 0)
			{
				Space* jumpUpLeft = *(this->corner + 8*upLeft->getRow() + upLeft->getCol() - 9);
				if(upLeft->getSpaceType() == 1 || upLeft->getSpaceType() == 2)
				{
					if(upLeft->getBlack() == false && jumpUpLeft->getSpaceType() == 0)
						{
							mp->newCol = jumpUpLeft->getCol();
							mp->newRow = jumpUpLeft->getRow();
							mp->valid = true;
							mp->jump = true;
							mp->jumped = upLeft;
							moves->saveMove(mp);
						}
				}
				else if(upLeft->getSpaceType() == 0)
				{
					mp->newCol = upLeft->getCol();
					mp->newRow = upLeft->getRow();
					mp->valid = true;
					mp->jump = false;
					moves->saveMove(mp);
				}
			}
			else if(upLeft->getSpaceType() == 0)
			{
				mp->newCol = upLeft->getCol();
				mp->newRow = upLeft->getRow();
				mp->valid = true;
				mp->jump = false;
				moves->saveMove(mp);
			}
		}
		//Check right up
		if(piece->getCol() <7 && piece->getRow() > 0)
		{
			moveInfo* mp = (moveInfo*)malloc(sizeof(moveInfo));
			mp->piece = piece;
			Space* upRight = *(this->corner + 8*piece->getRow() + piece->getCol() - 7);
			if(piece->getCol() <6 && piece->getRow() >1)
			{
				Space* jumpUpRight = *(this->corner + 8*upRight->getRow() + upRight->getCol() - 7);
				if(upRight->getSpaceType() == 1 || upRight->getSpaceType() == 2)
				{
					if(upRight->getBlack() == false && jumpUpRight->getSpaceType() == 0)
					{
						mp->newCol = jumpUpRight->getCol();
						mp->newRow = jumpUpRight->getRow();
						mp->valid = true;
						mp->jump = true;
						mp->jumped = upRight;
						moves->saveMove(mp);
					}
				}
				else if(upRight->getSpaceType() == 0)
				{
					mp->newCol = upRight->getCol();
					mp->newRow = upRight->getRow();
					mp->valid = true;
					mp->jump = false;
					moves->saveMove(mp);
				}
			}
			else if(upRight->getSpaceType() == 0)
			{
				mp->newCol = upRight->getCol();
				mp->newRow = upRight->getRow();
				mp->valid = true;
				mp->jump = false;
				moves->saveMove(mp);
			}
		}
	}
	if(piece->getSpaceType() == 2 && piece->getBlack())//check king
	{
		//check left down
		if(piece->getCol() > 0 && piece->getRow() < 7)
		{
			moveInfo* mp = (moveInfo*)malloc(sizeof(moveInfo));
			mp->piece = piece;
			Space* downLeft = *(this->corner + 8*piece->getRow() + piece->getCol() + 7);
			if(piece->getCol() > 1 && piece->getRow() <6)
			{
				Space* jumpDownLeft = *(this->corner + 8*downLeft->getRow() + downLeft->getCol() + 7);
				if(downLeft->getSpaceType() == 1 || downLeft->getSpaceType() == 2)
				{
					if(downLeft->getBlack() == false && jumpDownLeft->getSpaceType() == 0)
					{
						mp->newCol = jumpDownLeft->getCol();
						mp->newRow = jumpDownLeft->getRow();
						mp->valid = true;
						mp->jump = true;
						mp->jumped = downLeft;
						moves->saveMove(mp);
					}
				}
				else if(downLeft->getSpaceType() == 0)
				{
					mp->newCol = downLeft->getCol();
					mp->newRow = downLeft->getRow();
					mp->valid = true;
					moves->saveMove(mp);
				}
			}
			else if(downLeft->getSpaceType() == 0)
			{
				mp->newCol = downLeft->getCol();
				mp->newRow = downLeft->getRow();
				mp->valid = true;
				moves->saveMove(mp);
			}
		}
		//check right down
		if(piece->getCol() <6 && piece->getRow() < 6)
		{
			moveInfo* mp = (moveInfo*)malloc(sizeof(moveInfo));
			mp->piece = piece;
			Space* downRight = *(this->corner + 8*piece->getRow() + piece->getCol() + 9);
			if(piece->getCol() <6 && piece->getRow() < 6)
			{
				Space* jumpDownRight = *(this->corner + 8*downRight->getRow() + downRight->getCol() + 9);
				if(downRight->getSpaceType() == 1 || downRight->getSpaceType() == 2)
					{
						if(downRight->getBlack() == false && jumpDownRight->getSpaceType() == 0)
						{
							mp->newCol = jumpDownRight->getCol();
							mp->newRow = jumpDownRight->getRow();
							mp->valid = true;
							mp->jump = true;
							mp->jumped = downRight;
							moves->saveMove(mp);
						}
					}
				else if(downRight->getSpaceType() == 0)
				{
					mp->newCol = downRight->getCol();
					mp->newRow = downRight->getRow();
					mp->valid = true;
					mp->jump = false;
					moves->saveMove(mp);
				}
			}
			else if(downRight->getSpaceType() == 0)
			{
				mp->newCol = downRight->getCol();
				mp->newRow = downRight->getRow();
				mp->valid = true;
				mp->jump = false;
				moves->saveMove(mp);
			}
		}
	}
	return moves;
}

void Board::move(moveInfo* cMv)
{
	if(cMv->piece->getSpaceType() == 0)
	{
		perror("spot is empty");fflush(stderr);
	}
	if(!cMv->jump) //standard move
	{
		Space* piece = cMv->piece;
		int oldRow = piece->getRow();
		int oldCol = piece->getCol();
		piece->setCol(cMv->newCol);
		piece->setRow(cMv->newRow);
		if((piece->getBlack() && piece->getRow() == 0) || (!piece->getBlack() && piece->getRow() == 7))
		{
			piece = this->crown(piece);
		}
		Space** newSpot = this->corner + 8*cMv->newRow + cMv->newCol;
		*newSpot = piece; // piece has been moved
		Space** oldSpot = this->corner + 8*oldRow + oldCol;
		Space* uOSpot = new Empty();
		uOSpot->setCol(oldCol);
		uOSpot->setRow(oldRow);
		*oldSpot = uOSpot; // old spot is now empty
	}
	if(cMv->jump)
	{
		Space* piece = cMv->piece;
		int oldRow = piece->getRow();
		int oldCol = piece->getCol();
		piece->setCol(cMv->newCol);
		piece->setRow(cMv->newRow);
		if((piece->getBlack() && piece->getRow() == 0) || (!piece->getBlack() && piece->getRow() == 7))
		{
			piece = this->crown(piece);
		}
		Space** newSpot = this->corner + 8*cMv->newRow + cMv->newCol;
		*newSpot = piece; // piece has been moved
		Space** oldSpot = this->corner + 8*oldRow + oldCol;
		Space* uOSpot = new Empty();
		uOSpot->setCol(oldCol);
		uOSpot->setRow(oldRow);
		*oldSpot = uOSpot; // old spot is now empty
		Space* jumped = cMv->jumped;
		int jumpedCol = jumped->getCol();
		int jumpedRow = jumped->getRow();
		Space* uJSpot = new Empty();
		uJSpot->setRow(jumpedRow);
		uJSpot->setCol(jumpedCol);
		Space** jSpot = this->corner + 8*jumpedRow + jumpedCol;
		*jSpot = uJSpot; //piece that was jumped has been removed
	}
}

void Board::recordMove(moveInfo* move, int possibleMoves, const char* filename)
{
	Space* theMove = move->piece;
	bool team = theMove->getBlack();
	int type = theMove->getSpaceType();
	int col = move->newCol;
	int row = move->newRow;
	ofstream myfile;
	myfile.open (filename, ios::app);
	if(type == 1 && team)
	{
		myfile << "There were " << possibleMoves<<" possible moves. The move was a black pawn to column "<<col<<"  and row "<<row<<"\n Updated Board:\n";
	}
	if(type == 1 && !team)
	{
		myfile << "There were " << possibleMoves<<" possible moves. The move was a red pawn to column "<<col<<"  and row "<<row<<"\n Updated Board:\n";
	}
	if(type == 2 && team)
	{
		myfile << "There were " << possibleMoves<<" possible moves. The move was a black king to column "<<col<<"  and row "<<row<<"\n Updated Board:\n";
	}
	if(type == 2 && !team)
	{
		myfile << "There were " << possibleMoves<<" possible moves. The move was a red king to column "<<col<<"  and row "<<row<<"\n Updated Board:\n";
	}
	for(int row = 0; row<8; row++)
	{
		myfile<< "| ";
		for(int col = 0; col<8; col++)
		{
			Space* space = *(this->corner + row*8 +col);
			if(space->getSpaceType() == 0)
			{
					myfile<< " -- ";
			}
			else if(space->getSpaceType() == 1)
			{
				if(space->getBlack())
				{
					myfile<<" BP ";
				}
				else
				{
					myfile<<" RP ";
				}
			}
			else if(space->getSpaceType() == 2)
			{
				if(space->getBlack())
				{
					myfile<<" BK ";
				}
				else
				{
					myfile<<" RK ";
				}
			}
		}
		myfile<< " | \n";
	}
	myfile.close();
}

bool Board::checkWin()
{
	bool win = false;
	int totalBlack = 0;
	int totalRed = 0;
	for(int row = 0; row<8; row++)
	{
		for(int col = 0; col<8; col++)
		{
			Space* x = *(this->corner + 8*row +col);
			if(x->getSpaceType() == 1 || x->getSpaceType() == 2)
			{
				if(x->getBlack())
				{
					totalBlack++;
				}
				else if(!x->getBlack())
				{
					totalRed++;
				}
			}
		}
	}
	if(totalBlack == 0)
	{
		win = true;
		cout<<"RED WINS"<<endl;
	}
	if(totalRed == 0)
	{
		win = true;
		cout<<"BLACK WINS"<<endl;
	}
	return win;
}






