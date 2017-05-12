//============================================================================
// Name        : Entry.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
//#include <cregex>	//Non-existing!!
#include <regex.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include "TestingClass.h"
#include "TestingEmpty.h"
#include "TestingEmpty.h"		//no error
#include "Entry.h"

using namespace std;

typedef void (TestingClass::*FPsetGeneralID)(int);
typedef int (TestingClass::*FPrun)(void);
typedef int (TestingClass::*FPattack)(void);

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

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

	char *szPattern = "'?(\\d+)'?";
	regmatch_t what[8];
	regex_t regex;
	int iExecCode = 0;
	char szExecCode[16];

	regcomp(&regex, szPattern, REG_EXTENDED);

	for(int i=1; i < argc; ++i)
	{
		iExecCode = 0;
		memset(what, 0, sizeof(what));
		memset(szExecCode, 0, sizeof(szExecCode));

		switch(regexec(&regex, argv[i], 8, what, REG_NOTBOL))
		{
		case REG_NOMATCH:
			cout << "Unparseable arguments: " << argv[i] << endl;
			continue;
		case REG_OK:
			memcpy(szExecCode, argv[i] + what[1].rm_so, what[1].rm_eo - what[0].rm_so);
			iExecCode = atoi(szExecCode);
			break;
		default:
			break;
		}
		switch(iExecCode)
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
		case 7:
			TestingClass::testArgumentsByCRegex(argc, argv);
			break;
		case 8:
			TestingClass::testArgumentsByCppRegex(argc, argv);
			break;
		case 9:
			TestingClass::testArgumentsByBoostRegex(argc, argv);
			break;
		case 10:
			TestingClass::testCout();
			break;
		case 11:
			TestingClass::testException();
			break;
		default:
			cout << "Unavailable arguments: " << argv[i] << endl;
			break;
		}
	}
	regfree(&regex);
	return 0;
}
