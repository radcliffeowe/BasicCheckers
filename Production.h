/*
 * Production.h
 *
 *  Created on: Mar 3, 2021
 *      Author: radcl
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#define FILENAMELENGTHALLOWANCE 50
#include "Board.h"
#include "Space.h"
#include "Pawn.h"
#include "King.h"
#include "Empty.h"
#include "LLMove.h"
#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
#include <errno.h>

class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
};

#endif /* PRODUCTION_H_ */
