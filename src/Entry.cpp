//============================================================================
// Name        : Entry.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "TestingClass.h"
#include "TestingEmpty.h"
using namespace std;

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
	cout << "The sizeof of TestingClass is " << sizeof(TestingClass)
			<< " " << sizeof(TestingClass*) << endl; // prints !!!Hello World!!!
	cout << "The sizeof of TestingEmpty is " << sizeof(TestingEmpty)
			<< " " << sizeof(TestingEmpty*) << endl;
	cout << "The size of int is " << sizeof(int) << endl;
	cout << "The size of long is " << sizeof(long) << endl;
	cout << "The size of long long is " << sizeof(long long) << endl;
	cout << "The size of long long int is " << sizeof(long long int) << endl;
	cout << "The size of ptrdiff_t is " << sizeof(ptrdiff_t) << endl;

	testing = new TestingClass[8];
	delete[] testing;

	TestingClass::testSingleInherit();
	TestingClass::testMultiInherit();

	return 0;
}
