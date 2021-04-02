//============================================================================
// Name        : Checkers2.cpp
// Author      : Owen Radcliffe
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Production.h"
#include "Tests.h"

int main(int argc, char* argv[]) {
	cout<<"!!!Let's do HW5!!!"<<endl;
	Tests* tsP = new Tests();
	if(tsP->tests())
	{
        Production* pP = new Production();
        if(pP->prod(argc, argv))
        {
        	cout <<"Production passed." << endl;
        }
        delete(pP);
	}
	else
	{
		cout <<"Not all tests passed." << endl;
	}
	delete(tsP);
	return 0;
}
