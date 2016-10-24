//============================================================================
// Name        : Entry.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <boost/regex.hpp>
#include "TestingClass.h"
#include "TestingEmpty.h"
#include "TestingEmpty.h"		//no error
#include "Entry.h"

using namespace std;
using namespace boost;

typedef void (TestingClass::*FPsetGeneralID)(int);
typedef int (TestingClass::*FPrun)(void);
typedef int (TestingClass::*FPattack)(void);

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << "The size of bool is " << sizeof(bool) << endl;

	FPsetGeneralID fpsetGeneralID;
	FPrun fprun;
	FPattack fpattack;

	ofstream fileTest;
	TestingClass* testing;
	//current path is ./cpp-test-links.
	fileTest.open("data/test.data", ios::trunc|ios::binary|ios::out);
	testing = new TestingClass;

	fpsetGeneralID = TestingClass::setGeneralID;
	fprun = TestingClass::run;
	fpattack = (TestingClass::attack);
//	run = testing->run();
//	attack = testing->attack();
	cout << "The address of TestingClass.setGeneralID is " << fpsetGeneralID << endl;
	cout << "The address of TestingClass.run is " << fprun << endl;
	cout << "The address of TestingClass.attack is "<< fpattack << endl;
	cout << "The return of TestingClass::run is " << (testing->*fprun)() << endl;
	cout << "The return of TestingClass::attack is "<< (testing->*fpattack)() << endl;
//	testing->setGeneralID(0);
	fileTest.write((char *)testing, sizeof(TestingClass));
	fileTest.close();
	delete testing;
	
	manageTestingCases(argc, argv);

	return 0;
}

int manageTestingCases(int argc, char **argv)
{
	if(argc <= 1)
	{
		cout << "Invalid arguments. " << endl;
		return -1;
	}

	regex pattern("'?(\\d+)'?");
	cmatch what;//smatch what; it is also OK.

	for(int i=1; i < argc; ++i)
	{
		if(!regex_search(argv[i], what, pattern))
		{
			cout << "Invalid arguments: " << argv[i] << endl;
			continue;//no matching
		}
		else
		{
//			cout << "The size of what is " << what.size() << endl;
//			cout << "The what 0 is " << what[0].str() << endl;
//			cout << "The what 1 is " << what[1].str() << endl;

		}
		switch(atoi(what[1].str().data()))//string::const char *
		{
		case 1:
			TestingClass::testBasicDataType();
			break;
		case 2:
			TestingClass::testNewDelete();
			break;
		case 3:
			TestingClass::testSingleInherit();
			break;
		case 4:
			TestingClass::testMultiInherit();
			break;
		case 5:
			TestingClass::testVirSingleInherit();
			break;
		case 6:
			TestingClass::testVirMultiInherit();
			break;
		default:
			cout << "Invalid arguments: " << argv[i] << endl;
			break;
		}
	}
	return 0;
}
