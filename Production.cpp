/*
 * Production.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#include "Production.h"

Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char* argv[])
{
	printf("Starting Production\n");fflush(stdout);
	bool answer = true;
	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d interesting arguments.\n", argc-1);
		fflush(stdout);
		char filename[FILENAMELENGTHALLOWANCE];
		char* eptr=(char*) malloc(sizeof(char*));
		long aL=-1L;
		long bL = -1L;
		bool firstMove;
		int maxTurns;

		for(int i = 1; i<argc; i++) //don't want to read argv[0]
				{//argv[i] is a string

					switch(i)
					{
					case 1:
						//this is filename
						printf("The length of the filename is %d.\n",strlen(argv[i]));
						printf("The proposed filename is %s.\n", argv[i]);
						if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
						{
							puts("Filename is too long.");
							fflush(stdout);
							answer = false;
						}
						else
						{
							strcpy(filename, argv[i]);
							printf("Filename was %s.\n", filename);
							fflush(stdout);
						}
						break;
					case 2:
						//this is whether or not the computer is player 1
						aL = strtol(argv[i], &eptr, 10);
						firstMove = (bool) aL;
						if(firstMove)
						{
							printf("Computer is player 1\n");fflush(stdout);
						}
						else
						{
							printf("Computer is player 2\n");fflush(stdout);
						}
						break;
					case 3:
						//this is maximum amount of turns

						bL = strtol(argv[i], NULL, 10);
						maxTurns = (int)bL;
						if(maxTurns<0)
						{
							answer = false;
						}
						printf("Maximum number of turns is %d\n",maxTurns);fflush(stdout);
						break;

					default:
						puts("Unexpected argument count."); fflush(stdout);
						answer = false;
						break;
					}//end of switch
				}//end of for loop on argument count
				puts("after reading arguments"); fflush(stdout);
			//Initialize the board
			Board* gameBoard = new Board();
			Space** corner = (Space**)malloc(64 * sizeof(Space*));
			gameBoard->setCorner(corner);
			FILE* fp = fopen("gameLog.txt", "a+"); //open log file
			cout<<"a"<<endl;
			gameBoard->initFile(filename);
			puts("Initial Configuration:");fflush(stdout);
			gameBoard->displayBoard();
			for(int turn = 0; turn < maxTurns; turn++)
			{
				if(firstMove)//black goes first
				{
					int totalPossMoves = 0;
					moveInfo* bestMove = (moveInfo*)malloc(sizeof(moveInfo));
					bestMove->valid = false;
					bestMove->jump = false;
					for(int row = 0; row<8;row++)
					{
						for(int col = 0; col<8; col++)
						{
							Space* x = *(gameBoard->getCorner() + row*8 + col);
							if(x->getBlack())//black piece
							{
								LLMove* possibleMoves = gameBoard->checkMove(x);
								if(!possibleMoves->isEmpty())
								{
									LLMove* temp = possibleMoves;
									while(temp->getNext())//count possible moves
									{
										totalPossMoves++;
										temp = temp->getNext();
									}
									totalPossMoves++;
									moveInfo* bestMoveForPiece = possibleMoves->selectMove();
									if(bestMoveForPiece->jump && !bestMove->jump)
									{
										bestMove = bestMoveForPiece;
									}
									else if(!bestMove->jump)
									{
										bestMove = bestMoveForPiece;
									}
								}
							}
						}
					}
					if(totalPossMoves == 0)
					{
						perror("no possible moves");fflush(stderr);
					}
					else
					{
						//either the first possible jump is selected, or the last possible move, if no jumps are available
						gameBoard->move(bestMove);
						gameBoard->recordMove(bestMove, totalPossMoves, "gameLog.txt");
						gameBoard->displayBoard();
					}
				}
				else
				{
					int totalPossMoves= 0;
					moveInfo* opponentMove = (moveInfo*)malloc(sizeof(moveInfo*));
					opponentMove->valid = true;
					opponentMove->jump = false;
					cout<<"please enter the number of possible moves you have."<<endl;
					scanf("%d", &totalPossMoves);
					cout<<"please enter the row of the piece you would like to move."<<endl;
					int row = -1; int col = -1;
					scanf("%d", &row);
					cout<<"please enter the column of the piece you would like to move."<<endl;
					scanf(" %d", &col);
					printf("%d %d\n", row, col);fflush(stdout);
					if((row+col)%2 != 1)
					{
						perror("invalid space, please input a new row and column\n");fflush(stderr);
						scanf("%d %d", &row, &col);
					}
					Space* oppPiece = *(gameBoard->getCorner() + row*8 + col);
					opponentMove->piece = oppPiece;
					cout<<"please enter the row of the space you would like to move to."<<endl;
					int newRow = -1; int newCol = -1;
					scanf(" %d", &newRow);
					cout<<"please enter the column of the space you would like to move to."<<endl;
					scanf(" %d", &newCol);
					printf("%d %d \n", newRow, newCol);fflush(stdout);
					if((newRow+newCol)%2 != 1)
					{
						perror("invalid space, please input a new row and column\n");fflush(stderr);
						scanf("%d %d", &newRow, &newCol);
					}
					opponentMove->newCol = newCol; opponentMove->newRow = newRow;
					cout<<"Are you jumping over a black piece? Press 1 if yes, 0 if no."<<endl;
					int isJump = -1;
					scanf("%d", &isJump);
					if(isJump == 1)
					{
						opponentMove->jump = true;
						cout<<"Please enter the row of the piece you are jumping over."<<endl;
						int jRow = -1; int jCol = -1;
						scanf(" %d", &jRow);
						cout<<"Please enter the column of the piece you are jumping over."<<endl;
						scanf(" %d", &jCol);
						if((row+col)%2 != 1)
						{
							perror("invalid space, please input a new row and column\n");fflush(stderr);
							scanf("%d %d", &row, &col);
						}
						opponentMove->jumped = *(gameBoard->getCorner() + 8*jRow +jCol);
					}
					else
					{
						opponentMove->jump = false;
					}
					gameBoard->move(opponentMove);
					gameBoard->recordMove(opponentMove, totalPossMoves, "gameLog.txt");
					gameBoard->displayBoard();
				}
				gameBoard->checkWin();
				if(gameBoard->checkWin())
				{
					return answer;
				}
				else
				{
					firstMove = !firstMove;
				}
			}
			fclose(fp);
			cout<<"max number of turns, game over"<<endl;
			delete(gameBoard);
			free(corner);
	}
	return answer;
}
