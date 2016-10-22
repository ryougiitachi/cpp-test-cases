/*
 * TestingClass.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author:
 */

#include <iostream>
#include "TestSingleInheritLvl1.h"
#include "TestSingleInheritLvl2.h"
#include "TestSingleInheritLvl3.h"
#include "TestMultiInherit.h"
#include "TestingClass.h"

using namespace std;
using namespace itachi;
/***
***/
TestingClass::TestingClass() {
	this->generalID = 0;
	this->birthDate = 0;
	this->lifetime = 0;
	cout << "The address of TestingClass() instantiation is " << this << endl;
}

TestingClass::TestingClass(int generalID=0) {
	this->generalID = generalID;
	this->birthDate = 0;
	this->lifetime = 0;
	cout << "The address of TestingClass(int generalID) instantiation is " << this << endl;
}

/**
 *
 * */
TestingClass::~TestingClass() {
	//It uses reserve order for delete[]
	cout << "TestingClass is destructing " << this << endl;
}

/**
 * It is not necessary to add "static" for static member method in definition.
 * */
void TestingClass::testSingleInherit() {
	//p1lvl1 the 1st number is class name, and 2nd number is instantiated content.
	TestSingleInheritLvl1 *p1lvl1, *p1lvl2, *p1lvl3;

	cout << "Initialising p1lvl1 ... " << endl;
	p1lvl1 = new TestSingleInheritLvl1();
	cout << "Complete initialising p1lvl1 ... " << endl;

	cout << "Initialising p1lvl2 ... " << endl;
	p1lvl2 = new TestSingleInheritLvl2();
	cout << "Complete initialising p1lvl2 ... " << endl;

	cout << "Initialising p1lvl3 ... " << endl;
	p1lvl3 = new TestSingleInheritLvl3();
	cout << "Complete initialising p1lvl3 ... " << endl;

	cout << "Destorying p1lvl1 ... " << endl;
	delete p1lvl1;p1lvl1=NULL;
	cout << "Complete destorying p1lvl1 ... " << endl;

	cout << "Destorying p1lvl2 ... " << endl;
	delete p1lvl2;p1lvl2=NULL;
	cout << "Complete destorying p1lvl2 ... " << endl;

	cout << "Destorying p1lvl3 ... " << endl;
	delete p1lvl3;p1lvl3=NULL;
	cout << "Complete destorying p1lvl3 ... " << endl;
}

/**
 * */
void TestingClass::testMultiInherit() {
	TestMultiInheritLvl1 *p1lvl3=NULL;
	TestMultiInheritLvl1A *p1alvl3=NULL;
	TestMultiInheritLvl2A *p2alvl3=NULL;
	TestMultiInheritLvl2B *p2blvl3=NULL;
	TestMultiInheritLvl2C *p2clvl3=NULL;

	cout << "Initialising p1lvl3 ... " << endl;
	//compile error
	//TestMultiInheritLvl1 is an ambiguous base of TestMultiInheritLvl3
	//a class beyond 2 levels can't be a base class for a multi-inheriting class ?
//	p1lvl3 = new TestMultiInheritLvl3();
	cout << "Complete initialising p1lvl3 ... " << endl;

	cout << "Initialising p1alvl3 ... " << endl;
	p1alvl3 = new TestMultiInheritLvl3();
	cout << "Complete initialising p1alvl3 ... " << endl;

	//if there is an assignment between 2 classes without inherited relationship,
	//cannot convert 'itachi::TestSingleInheritLvl3*' to 'itachi::TestMultiInheritLvl2A*' in assignment.
	cout << "Initialising p2alvl3 ... " << endl;
	p2alvl3 = new TestMultiInheritLvl3();
	cout << "Complete initialising p2alvl3 with address " << p2alvl3 << endl;

	cout << "Initialising p2blvl3 ... " << endl;
	p2blvl3 = new TestMultiInheritLvl3();
	cout << "Complete initialising p2blvl3 ... " << endl;

	cout << "Initialising p2clvl3 ... " << endl;
	p2clvl3 = new TestMultiInheritLvl3();
	cout << "Complete initialising p2clvl3 ... " << endl;

	cout << "Destorying p1lvl3 ... " << endl;
	delete p1lvl3;p1lvl3=NULL;//delete can delete a null point ?
	cout << "Complete destorying p1lvl3 ... " << endl;

	cout << "Destorying p1alvl3 ... " << endl;
	delete p1alvl3;p1alvl3=NULL;//delete can delete a null point ?
	cout << "Complete destorying p1alvl3 ... " << endl;

	cout << "Destorying p2alvl3 ... " << endl;
	delete p2alvl3;p2alvl3=NULL;
	cout << "Complete destorying p2alvl3 ... " << endl;

	cout << "Destorying p2blvl3 ... " << endl;
	delete p2blvl3;p2blvl3=NULL;
	cout << "Complete destorying p2blvl3 ... " << endl;

	cout << "Destorying p2clvl3 ... " << endl;
	//It is required!!! Otherwise, the memory space won't be free till program exits, seemingly.
	delete p2clvl3;p2clvl3=NULL;
	cout << "Complete destorying p2clvl3 ... " << endl;
}
