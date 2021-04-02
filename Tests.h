/*
 * Tests.h
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "Space.h"
#include "Board.h"
#include "Pawn.h"
#include "King.h"
#include "Empty.h"
#include "Log.h"
#include <typeinfo>
#include <iostream>
using namespace std;
#include "stdio.h"

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
	bool testSetGetBlack();
	bool testSetGetDark();
	bool testSetGetCorner();
	bool testGetSpaceType();
	bool testInitStd();
	bool testDisplayBoard();
	bool testCrown();
	bool testSetGetNext();
	bool testSetGetPrev();
	bool testSetGetMove();
	bool testIsEmpty();
	bool testSaveMove();
	bool testCheckMove();
	bool testSelectMove();
	bool testInitFile();
	bool testMove();
	bool testRecordMove();
	bool testCheckWin();
	bool testTurn();
};

#endif /* TESTS_H_ */
