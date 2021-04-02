/*
 * Tests.cpp
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#include "Tests.h"

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{
	bool ok1 = testSetGetCorner();
	bool ok2 = testSetGetBlack();
	bool ok3 = testSetGetDark();
	bool ok4 = testGetSpaceType();
	bool ok5 = testInitStd();
	bool ok6 = testDisplayBoard();
	bool ok7 = testCrown();
	bool ok8 = testSetGetNext();
	bool ok9 = testSetGetPrev();
	bool ok10 = testSetGetMove();
	bool ok11 = testIsEmpty();
	bool ok12 = testSaveMove();
	bool ok13 = testCheckMove();
	bool ok14 = testSelectMove();
	bool ok15 = testInitFile();
	bool ok16 = testMove();
	bool ok17 = testRecordMove();
	bool ok18 = testCheckWin();
	//bool ok19 = testTurn();
	bool answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11 && ok12 && ok13 && ok14 && ok15 && ok16 && ok17 && ok18;// && ok19;
	return answer;
}

bool Tests::testSetGetCorner()
{
	bool ok = true;
	cout<<"--------starting testSetGetCorner-------"<<endl;
	//Case 1
	Board* B = new Board();
	Space** bStart = (Space**)malloc(64 * sizeof(Space*));
	B->setCorner(bStart);
	if(B->getCorner() != bStart)
	{
		ok = false;
		cout<<"testSetGetCorner failed"<<endl;
	}
	else
	{
		cout<<"testSetGetCorner passed"<<endl;
	}
	return ok;
}

bool Tests::testSetGetBlack()
{
	bool passed = true;
	cout<<"--------starting testSetGetBlack---------------"<<endl;
	//Case 1, setting a pawn to black
	Space* testPawn = new Pawn();
	testPawn->setBlack();
	if(!testPawn->getBlack())
	{
		passed = false;
		cout<< "case 1 failed"<<endl;
	}
	else
	{
		cout<<"case 1 passed"<<endl;
	}
	//Case 2, setting a king to black
	Space* testKing = new King();
	testKing->setBlack();
	if(!testKing->getBlack())
	{
		passed = false;
		cout<<"case 2 failed"<<endl;
	}
	else
	{
		cout<<"case 2 passed"<<endl;
	}
	if(passed)
	{
		cout<<"testSetGetBlack passed"<<endl;
	}
	return passed;
}

bool Tests::testSetGetDark()
{
	bool ok = true;
	cout<<"-------------starting testSetGetDark-----------"<<endl;
	Space* testPawn = new Pawn();
	testPawn->setDark();
	Space* testKing = new King();
	testKing->setDark();
	Space* testEmpty = new Empty();
	testEmpty->setDark();
	if(!testPawn->getDark() || !testKing->getDark() || !testEmpty->getDark())
	{
		ok = false;
		cout<<"testSetGetDark failed"<<endl;
	}
	else
	{
		cout<<"testSetGetDark passed"<<endl;
	}
	return ok;
}

bool Tests::testGetSpaceType()
{
	bool ok = true;
	cout<<"--------starting testGetSpaceType--------"<<endl;
	// Pawn
	Space* tPawn = new Pawn();
	if(tPawn->getSpaceType() != 1)
	{
		ok = false;
		cout<<"pawn failed"<<endl;
	}
	else
	{
		cout<<"pawn passed"<<endl;
	}
	// King
	Space* tKing = new King();
	if(tKing->getSpaceType() != 2)
	{
		ok = false;
		cout<<"king failed"<<endl;
	}
	else
	{
		cout<<"king passed"<<endl;
	}
	// Empty
	Space* tEmp = new Empty();
	if(tEmp->getSpaceType() != 0)
	{
		ok = false;
		cout<<"empty failed"<<endl;
	}
	else
	{
		cout<<"empty passed"<<endl;
	}
	if(ok)
	{
		cout<<"testGetSpaceType passed"<<endl;
	}
	else
	{
		cout<<"testGetSpaceType failed"<<endl;
	}
	return ok;
}

bool Tests::testInitStd()
{
	bool ok = true;
	cout<<"-------starting testInitStd---------"<<endl;
	//Case 1, initializing a board
	int totalEmpty = 0;
	int totalPawn = 0;
	int totalBlack = 0;
	int totalRed = 0;
	Board* testBoard = new Board();
	Space** testStart = (Space**)malloc(64* sizeof(Space*));
	testBoard->setCorner(testStart);
	testBoard->initStd();
	for(int row = 0; row<8;row++)
	{
		for(int col = 0; col<8; col++)
		{
			Space* spot = *(testStart + row*8 + col);
			if(spot->getSpaceType() == 0)
			{
				totalEmpty++;
			}
			if(spot->getSpaceType() == 1)
			{
				totalPawn++;
				if(spot->getBlack())
				{
					totalBlack++;
				}
				else
				{
					totalRed++;
				}
			}
		}
	}
	cout<<totalPawn<<endl<<totalEmpty<<endl<< totalRed<< endl<< totalBlack<<endl;
	if(totalPawn != 16 || totalEmpty != 48 || totalRed != 8 || totalBlack != 8)
	{
		ok = false;
		cout<<"testInit failed"<<endl;
	}
	else
	{
		cout<<"testInit passed"<<endl;
	}
	return ok;
}

bool Tests::testDisplayBoard()
{
	bool ok = true;
	cout<<"-------starting testDisplayBoard--------"<<endl;
	Board* B = new Board();
	Space** testStart = (Space**)malloc(64* sizeof(Space*));
	B->setCorner(testStart);
	B->initStd();
	Space* bTest = *(testStart);
	bTest->setBlack();
	B->crown(bTest);
	B->displayBoard();
	printf("Does this look right? Press y if yes\n");fflush(stdout);
	char a = 'a';
	scanf("%c", &a);
	if(a!='y')
	{
		ok = false;
		cout<<"testDisplayBoard failed"<<endl;
	}
	else
	{
		cout<<"testDisplayBoard passed"<<endl;
	}
	return ok;
}

bool Tests::testCrown()
{
	bool ok = true;
	cout<<"--------starting testCrown--------"<<endl;
	//Case 1, crowning a pawn
	Board* A = new Board();
	Space** aStart = (Space**)malloc(64 * sizeof(Space*));
	A->setCorner(aStart);
	A->initStd();
	Space* aTest = *(aStart);
	aTest->setBlack();
	Space* aNewSpace = A->crown(aTest);
	Space* aSpotOnBoard = *(aStart);
	if(aSpotOnBoard->getSpaceType() != 2 || aSpotOnBoard != aNewSpace)
	{
		ok = false;
		cout<<"case 1 failed"<<endl;
	}
	else
	{
		cout<<"case 1 passed"<<endl;
	}
	//Case 2, crowning an empty spot
	Board* B = new Board();
	Space** bStart = (Space**)malloc(64 * sizeof(Space*));
	B->setCorner(bStart);
	B->initStd();
	Space* bTest = *(bStart + 25);
	Space* bNewSpace = B->crown(bTest);
	Space* bSpotOnBoard = *(bStart +25);
	if(bSpotOnBoard->getSpaceType() != 0 || bSpotOnBoard != bNewSpace)
	{
		ok = false;
		cout<<"case 2 failed"<<endl;
	}
	else
	{
		cout<<"case 2 passed"<<endl;
	}
	if(ok)
	{
		cout<<"testCrown passed"<<endl;
	}
	else
	{
		cout<<"testCrown failed"<<endl;
	}
	return ok;
}

bool Tests::testSetGetNext()
{
	bool ok = false;
	cout<< "----------starting testSetGetNext----------" << endl;fflush(stdout);
	// Test Case 1
	cout<< "starting case 1, setting and getting a search node from a search list"<< endl;fflush(stdout);
	LLMove* testMove = new LLMove();
	LLMove* testNextMove = new LLMove();
	testMove->setNext(testNextMove);
	if(testMove->getNext() == testNextMove)
	{
		ok = true;
		cout<< "case 1 passed"<< endl;fflush(stdout);
	}
	else
	{
		cout<< "case 1 failed"<< endl;fflush(stdout);
	}
	if(ok)
	{
		cout<<"testSetGetNext passed"<< endl;fflush(stdout);
	}
	else
	{
		cout<<"testSetGetNext failed"<< endl;fflush(stdout);
	}
	return ok;
}

bool Tests::testSetGetPrev()
{
	bool ok = true;
	cout<< "----------starting testSetGetPrev----------" << endl;fflush(stdout);
	// Test Case 1
	cout<< "starting case 1, setting and getting a search node from a search list"<< endl;fflush(stdout);
	LLMove* testMove = new LLMove();
	LLMove* testNextMove = new LLMove();
	testMove->setPrev(testNextMove);
	if(testMove->getPrev() != testNextMove)
	{
		ok = false;
		cout<< "case 1 failed"<< endl;fflush(stdout);
	}
	else
	{
		cout<< "case 1 passed"<< endl;fflush(stdout);
	}
	if(ok)
	{
		cout<<"testSetGetPrev passed"<< endl;fflush(stdout);
	}
	else
	{
		cout<<"testSetGetPrev failed"<< endl;fflush(stdout);
	}
	return ok;
}

bool Tests::testSetGetMove()
{
	bool ok = true;
	cout<< "----------starting testSetGetMove----------" << endl;fflush(stdout);
	// Test Case 1
	cout<< "starting case 1, setting and getting a search node from a search list"<< endl;fflush(stdout);
	LLMove* testMove = new LLMove();
	moveInfo* testInfo = (moveInfo*)malloc(sizeof(moveInfo));
	testMove->setMove(testInfo);
	if(testMove->getMove() != testInfo)
	{
		ok = false;
		cout<< "case 1 failed"<< endl;fflush(stdout);
	}
	else
	{
		cout<< "case 1 passed"<< endl;fflush(stdout);
	}
	if(ok)
	{
		cout<<"testSetGetMove passed"<< endl;fflush(stdout);
	}
	else
	{
		cout<<"testSetGetMove failed"<< endl;fflush(stdout);
	}
	return ok;
}

bool Tests::testIsEmpty()
{
	bool ok = true;
	cout << "---------starting testIsEmpty--------"<< endl;fflush(stdout);
	//Test Case 1
	cout<< "starting case 1, empty list"<< endl;fflush(stdout);
	LLMove* testMove = new LLMove();
	if(testMove->isEmpty() != true)
	{
		ok = false;
		cout<< "case 1 failed"<< endl;fflush(stdout);
	}
	else
	{
		cout<< "case 1 passed"<< endl;fflush(stdout);
	}
	//Test Case 2
	cout<< "starting case 2, nonempty list"<< endl;fflush(stdout);
	LLMove* testMove1 = new LLMove();
	moveInfo* testInfo = (moveInfo*)malloc(sizeof(moveInfo));
	testMove1->setMove(testInfo);
	if(testMove1->isEmpty())
	{
		ok = false;
		cout<< "case 2 failed"<< endl;fflush(stdout);
	}
	else
	{
		cout<< "case 2 passed"<< endl;fflush(stdout);
	}
	if(ok)
	{
		cout<< "testIsEmpty passed both cases"<< endl;fflush(stdout);
	}
	else
	{
		cout<< "testIsEmpty failed at least one test"<< endl;fflush(stdout);
	}
	return ok;
}

bool Tests::testSaveMove()
{
	bool ok = true;
	cout<< "--------starting testSaveMove--------"<< endl;fflush(stdout);
	//Test Case 1
	cout<< "starting case 1, saving to a list of 1"<< endl;fflush(stdout);
	LLMove* testSearch = new LLMove();
	moveInfo* testMove = (moveInfo*)malloc(sizeof(moveInfo));
	testSearch->setMove(testMove);
	moveInfo* testMoveSaved = (moveInfo*)malloc(sizeof(moveInfo));
	testSearch->saveMove(testMoveSaved);
	LLMove* temp = testSearch;
	while(temp->getNext())
	{
		temp = temp->getNext();
	}
	moveInfo* checkMove = temp->getMove();
	if(checkMove != testMoveSaved)
	{
		ok = false;
		cout<< "case 1 failed"<< endl;fflush(stdout);
	}
	else
	{
		cout<< "case 1 passed"<< endl;fflush(stdout);
	}
	// Test Case 2
	cout<< "starting case 2, an empty list"<< endl;fflush(stdout);
	LLMove* testSearch1 = new LLMove();
	moveInfo* testMove1 = (moveInfo*)malloc(sizeof(moveInfo));
	testSearch1->saveMove(testMove1);
	moveInfo* resultMove = testSearch1->getMove();
	if(resultMove != testMove1)
	{
		ok = false;
		cout<< "case 2 failed"<< endl;fflush(stdout);
	}
	else
	{
		cout<< "case 2 passed"<< endl;fflush(stdout);
	}
	if(ok)
	{
		cout<< "testSaveMove passed both cases"<< endl;fflush(stdout);
	}
	else
	{
		cout<< "testSaveMove failed at least one case"<< endl;fflush(stdout);
	}
	return ok;
}

bool Tests::testCheckMove()
{
	bool ok = true;
	cout<<"--------starting testCheckMove----------"<<endl;
	//Case 1, no bordering pieces of opposite team
	Board* A = new Board();
	Space** aStart = (Space**)malloc(64 * sizeof(Space*));
	A->setCorner(aStart);
	A->initStd();
	Space* aTest = *(aStart + 50);
	LLMove* testMoves = A->checkMove(aTest);
	int tmLength = 0;
	LLMove* temp = testMoves;
	while(temp->getNext())
	{
		temp = temp->getNext();
		tmLength++;
	}
	tmLength++;
	Space* aTest2 = *(aStart + 52);
	A->crown(aTest2);
	LLMove* testMoves2 = A->checkMove(aTest2);
	int tm2Length = 0;
	LLMove* temp2 = testMoves2;
	while(temp2->getNext())
	{
		temp2 = temp2->getNext();
		tm2Length++;
	}
	tm2Length++;
	if(tmLength != 2 || tm2Length != 2)
	{
		ok = false;
		cout<<"case 1 failed"<<endl;
	}
	else
	{
		cout<<"case 1 passed"<<endl;
	}
	//Case 2, bordering pieces of opposite team, but no open spots past them
	Board* B = new Board();
	Space** bStart = (Space**)malloc(64 * sizeof(Space*));
	B->setCorner(bStart);
	B->initStd();
	//Pawn
	Pawn* tp = new Pawn();
	Space* bTest = *(B->getCorner() + 18);
	int bRow = bTest->getRow();
	int bCol = bTest->getCol();
	tp->setRow(bRow);
	tp->setCol(bCol);
	tp->setBlack();
	*(B->getCorner() + 18) = tp;
	LLMove* bResult = B->checkMove(tp);
	int bResLength = 0;
	LLMove* bTemp = bResult;
	while(bTemp->getNext())
	{
		bTemp = bTemp->getNext();
		bResLength++;
	}
	bResLength++;
	//King
	King* tk = new King();
	Space* bTest2 = *(B->getCorner() + 20);
	int bRow1 = bTest2->getRow();
	int bCol1 = bTest2->getCol();
	tk->setRow(bRow1);
	tk->setCol(bCol1);
	tk->setBlack();
	*(B->getCorner() + 20) = tk;
	LLMove* bResult2 = B->checkMove(tk);
	int bRes2Length = 0;
	LLMove* bTemp2 = bResult2;
	while(bTemp2->getNext())
	{
		bTemp2 = bTemp2->getNext();
		bRes2Length++;
	}
	bRes2Length++;
	if(bResult->isEmpty() != true || bRes2Length != 2)
	{
		ok = false;
		cout<<"case 2 failed"<<endl;
	}
	else
	{
		cout<<"case 2 passed"<<endl;
	}
	//Case 3, valid jump
	Board* C = new Board();
	Space** cStart = (Space**)malloc(64 * sizeof(Space*));
	C->setCorner(cStart);
	C->initStd();
	//Pawn
	Pawn* pw = new Pawn();
	Space* cTest = *(C->getCorner() + 16);
	int cRow = cTest->getRow();
	int cCol = cTest->getCol();
	pw->setRow(cRow);
	pw->setCol(cCol);
	pw->setBlack();
	*(C->getCorner() + 16) = pw;
	Space* cEmpty = *(C->getCorner() + 2);
	Empty* emp = new Empty();
	emp->setRow(cEmpty->getRow());
	emp->setCol(cEmpty->getCol());
	*(C->getCorner() + 2) = emp;
	LLMove* cResult = C->checkMove(pw);
	int cResLength = 0;
	LLMove* cTemp = cResult;
	while(cTemp->getNext())
	{
		cTemp = cTemp->getNext();
		cResLength++;
	}
	cResLength++;
	//King
	Space* cTest1 = *(C->getCorner() + 4);
	King* kg = new King();
	int cRow1 = cTest1->getRow();
	int cCol1 = cTest1->getCol();
	kg->setRow(cRow1);
	kg->setCol(cCol1);
	kg->setBlack();
	*(C->getCorner() + 4) = kg;
	LLMove* cResult1 = C->checkMove(kg);
	int cRes2Length = 0;
	LLMove* c2Temp = cResult1;
	while(c2Temp->getNext())
	{
		c2Temp = c2Temp->getNext();
		cRes2Length++;
	}
	cRes2Length++;
	if(cResLength != 1 || cRes2Length != 2)
	{
		ok = false;
		cout<<"case 3 failed"<<endl;
	}
	else
	{
		cout<<"case 3 passed"<<endl;
	}
	if(ok)
	{
		cout<<"testCheckMove passed"<<endl;
	}
	else
	{
		cout<<"testCheckMove failed"<<endl;
	}
	return ok;
}

bool Tests::testSelectMove()
{
	bool ok = true;
	cout<<"---------starting testSelectMove------------"<<endl;
	//Case 1, no possible jumps, select regular move
	Board* A = new Board();
	Space** aStart = (Space**)malloc(64 * sizeof(Space*));
	A->setCorner(aStart);
	A->initStd();
	Space* aTest = *(aStart + 50);
	LLMove* testMoves = A->checkMove(aTest);
	moveInfo* aRes = testMoves->selectMove();
	if(aRes->jump || !aRes->valid || aRes->newCol != 3 || aRes->newRow != 5 || aRes->piece != aTest)
	{
		ok = false;
		cout<<"case 1 failed"<<endl;
	}
	else
	{
		cout<<"case 1 passed"<<endl;
	}
	//Case 2, possible moves and jumps, should select jump
	Board* B = new Board();
	Space** bStart = (Space**)malloc(64 * sizeof(Space*));
	B->setCorner(bStart);
	B->initStd();
	King* tk = new King();
	Space* bTest2 = *(B->getCorner() + 20);
	int bRow1 = bTest2->getRow();
	int bCol1 = bTest2->getCol();
	tk->setRow(bRow1);
	tk->setCol(bCol1);
	tk->setBlack();
	*(B->getCorner() + 20) = tk;
	Space* cEmpty = *(B->getCorner() + 2);
	Empty* emp = new Empty();
	emp->setRow(cEmpty->getRow());
	emp->setCol(cEmpty->getCol());
	*(B->getCorner() + 2) = emp;
	LLMove* bMoves = B->checkMove(tk);
	moveInfo* bRes = bMoves->selectMove();
	if(bRes->newCol != 2 || bRes->newRow != 0 || !bRes->jump || !bRes->valid || bRes->jumped != *(bStart + 11) || bRes->piece != tk)
	{
		ok = false;
		cout<<"case 2 failed"<<endl;
	}
	else
	{
		cout<<"case 2 passed"<<endl;
	}
	if(ok)
	{
		cout<<"testSelectMove passed"<<endl;
	}
	else
	{
		cout<<"testSelectMove failed"<<endl;
	}
	return ok;
}

bool Tests::testInitFile()
{
	bool ok = true;
	cout<<"-------starting testInitFile---------"<<endl;
	//Case 1, initializing a standard board
	int totalEmpty = 0;
	int totalPawn = 0;
	int totalBlack = 0;
	int totalRed = 0;
	Board* testBoard = new Board();
	Space** testStart = (Space**)malloc(64* sizeof(Space*));
	testBoard->setCorner(testStart);
	testBoard->initFile("testFile1.txt");
	testBoard->displayBoard();
	for(int row = 0; row<8;row++)
	{
		for(int col = 0; col<8; col++)
		{
			Space* spot = *(testStart + row*8 + col);
			if(spot->getSpaceType() == 0)
			{
				totalEmpty++;
			}
			if(spot->getSpaceType() == 1)
			{
				totalPawn++;
				if(spot->getBlack())
				{
					totalBlack++;
				}
				else
				{
					totalRed++;
				}
			}
		}
	}
	cout<<totalPawn<<endl<<totalEmpty<<endl<< totalRed<< endl<< totalBlack<<endl;
	if(totalPawn != 16 || totalEmpty != 48 || totalRed != 8 || totalBlack != 8)
	{
		ok = false;
		cout<<"case 1 failed"<<endl;
	}
	else
	{
		cout<<"case 1 passed"<<endl;
	}
	//Case 2, initializing a custom configuration
	int totalEmpty2 = 0;
	int totalPieces2 = 0;
	int totalBlack2 = 0;
	int totalRed2 = 0;
	Board* testBoard2 = new Board();
	Space** testStart2 = (Space**)malloc(64* sizeof(Space*));
	testBoard2->setCorner(testStart2);
	testBoard2->initFile("testFile2.txt");
	testBoard2->displayBoard();
	for(int row = 0; row<8;row++)
	{
		for(int col = 0; col<8; col++)
		{
			Space* spot = *(testStart2 + row*8 + col);
			if(spot->getSpaceType() == 0)
			{
				totalEmpty2++;
			}
			if(spot->getSpaceType() == 1 || spot->getSpaceType() == 2)
			{
				totalPieces2++;
				if(spot->getBlack())
				{
					totalBlack2++;
				}
				else
				{
					totalRed2++;
				}
			}
		}
	}
	cout<<totalPieces2<<endl<<totalEmpty2<<endl<< totalRed2<< endl<< totalBlack2<<endl;
	if(totalPieces2 != 10 || totalEmpty2 != 54 || totalRed2 != 5 || totalBlack2 != 5)
	{
		ok = false;
		cout<<"case 2 failed"<<endl;
	}
	else
	{
		cout<<"case 2 passed"<<endl;
	}
	if(ok)
	{
		cout<<"testInitFile passed"<<endl;
	}
	else
	{
		cout<<"testInitFile failed"<<endl;
	}
	return ok;
}

bool Tests::testMove()
{
	bool ok = true;
	cout<<"--------starting testMove---------"<<endl;
	//case 1, no jumps, pawn forward
	Board* A = new Board();
	Space** aStart = (Space**)malloc(64 * sizeof(Space*));
	A->setCorner(aStart);
	A->initFile("testMove1.txt");
	Space* aTest = *(aStart + 42);
	LLMove* aMoves = A->checkMove(aTest);
	moveInfo* aSelMove = aMoves->selectMove();
	A->move(aSelMove);
	Space* aNewSpot = *(aStart + 35);
	Space* aOldSpot = *(aStart + 42);
	if(aNewSpot->getSpaceType() != 1 || !aNewSpot->getBlack() || aOldSpot->getSpaceType() != 0)
	{
		ok = false;
		cout<<"case 1 space is not updated"<<endl;
	}
	else
	{
		cout<<"case 1 space is updated. Does the board look correct? Press y if yes."<<endl;
		A->displayBoard();
		char a = 'a';
		scanf(" %c", &a);
		if(a != 'y')
		{
			ok = false;
			cout<<"board display is not updated"<<endl;
		}
		else
		{
			cout<<"board display is updated"<<endl;
		}
	}
	//Case 2, no jumps, king backwards
	Board* B = new Board();
	Space** bStart = (Space**)malloc(64 * sizeof(Space*));
	B->setCorner(bStart);
	B->initFile("testMove2.txt");
	Space* bTest = *(bStart + 35);
	LLMove* bMoves = B->checkMove(bTest);
	moveInfo* bSelMove = bMoves->selectMove();
	B->move(bSelMove);
	Space* bNewSpot = *(bStart + 44);
	Space* bOldSpot = *(bStart + 35);
	if(bNewSpot->getSpaceType() != 2 || !bNewSpot->getBlack() || bOldSpot->getSpaceType() != 0)
	{
		ok = false;
		cout<<"case 2 space is not updated"<<endl;
	}
	else
	{
		cout<<"case 2 space is updated. Does the board look correct? Press y if yes."<<endl;
		B->displayBoard();
		char b = 'a';
		scanf(" %c", &b);
		if(b != 'y')
		{
			ok = false;
			cout<<"board display is not updated"<<endl;
		}
		else
		{
			cout<<"board display is updated"<<endl;
		}
	}
	//Case 3, a jump, space should be updated and jumped piece should be removed from board
	Board* C = new Board();
	Space** cStart = (Space**)malloc(64 * sizeof(Space*));
	C->setCorner(cStart);
	C->initFile("testMove3.txt");
	Space* cTest = *(cStart + 44);
	LLMove* cMoves = C->checkMove(cTest);
	moveInfo* cSelMove = cMoves->selectMove();
	C->move(cSelMove);
	Space* cJumped = *(cStart + 35);
	Space* cNewSpot = *(cStart + 26);
	Space* cOldSpot = *(cStart + 44);
	if(cNewSpot->getSpaceType() != 2 || !cNewSpot->getBlack() || cJumped->getSpaceType() != 0 || cOldSpot->getSpaceType() != 0)
	{
		ok = false;
		cout<<"case 3 space is not updated"<<endl;
	}
	else
	{
		cout<<"case 3 space is updated. Does the board look correct? Press y if yes."<<endl;
		C->displayBoard();
		char c = 'a';
		scanf(" %c", &c);
		if(c != 'y')
		{
			ok = false;
			cout<<"board display is not updated"<<endl;
		}
		else
		{
			cout<<"board display is updated"<<endl;
		}
	}
	if(ok)
	{
		cout<<"testMove passed"<<endl;
	}
	else
	{
		cout<<"testMove failed"<<endl;
	}
	return ok;
}

bool Tests::testRecordMove()
{
	bool ok = true;
	cout<<"--------starting testRecordMove---------"<<endl;
	//Case 1, recording a series of moves to a file
	Board* A = new Board();
	Space** aStart = (Space**)malloc(64 * sizeof(Space*));
	A->setCorner(aStart);
	A->initFile("testRecord.txt");
	Space* aTest = *(aStart + 40);
	LLMove* aMoves = A->checkMove(aTest);
	moveInfo* aSelMove = aMoves->selectMove();
	A->move(aSelMove);
	A->recordMove(aSelMove, 7, "testRecordOutput.txt");
	Space* aTest2 = *(aStart + 17);
	moveInfo* test2Move = (moveInfo*)malloc(sizeof(moveInfo));
	test2Move->jump = false;
	test2Move->newCol = 0;
	test2Move->newRow = 3;
	test2Move->piece = aTest2;
	A->move(test2Move);
	A->recordMove(test2Move, 7, "testRecordOutput.txt");
	cout<<"Did this create an output file with the correct information? Press y if yes"<<endl;
	char a = 'a';
	scanf(" %c", &a);
	if(a != 'y')
	{
		ok = false;
		cout<<"testRecordMove failed"<<endl;
	}
	else
	{
		cout<<"testRecordMove passed"<<endl;
	}
	return ok;
}

bool Tests::testCheckWin()
{
	bool ok = true;
	cout<<"-------starting testCheckWin-------"<<endl;
	//Case 1, not a win
	Board* A = new Board();
	Space** aStart = (Space**)malloc(64 * sizeof(Space*));
	A->setCorner(aStart);
	A->initFile("testWinFalse.txt");
	A->displayBoard();
	if(A->checkWin())
	{
		ok = false;
		cout<<"case 1 failed"<<endl;
	}
	else
	{
		cout<<"case 1 passed"<<endl;
	}
	//Case 2, is a win
	Board* B = new Board();
	Space** bStart = (Space**)malloc(64 * sizeof(Space*));
	B->setCorner(bStart);
	B->initFile("testWinTrue.txt");
	B->displayBoard();
	if(!B->checkWin())
	{
		ok = false;
		cout<<"case 2 failed"<<endl;
	}
	else
	{
		cout<<"case 2 passed"<<endl;
	}
	if(ok)
	{
		cout<<"testCheckWin passed"<<endl;
	}
	else
	{
		cout<<"testCheckWin failed"<<endl;
	}
	return ok;
}




















