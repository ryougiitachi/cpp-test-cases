/*
 * TestingClass.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author:
 */

#include <iostream>
#include "TestingEmpty.h"
#include "TestSingleInheritLvl1.h"
#include "TestSingleInheritLvl2.h"
#include "TestSingleInheritLvl3.h"
#include "TestMultiInherit.h"
#include "TestVirSingleInherit.h"
#include "TestVirMultiInherit.h"
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

void TestingClass::testBasicDataType() {
	cout << "The sizeof of TestingClass is " << sizeof(TestingClass)
			<< " " << sizeof(TestingClass*) << endl; // prints !!!Hello World!!!
	cout << "The sizeof of TestingEmpty is " << sizeof(TestingEmpty)
			<< " " << sizeof(TestingEmpty*) << endl;
	cout << "The size of int is " << sizeof(int) << endl;
	cout << "The size of long is " << sizeof(long) << endl;
	cout << "The size of long long is " << sizeof(long long) << endl;
	cout << "The size of long long int is " << sizeof(long long int) << endl;
	cout << "The size of ptrdiff_t is " << sizeof(ptrdiff_t) << endl;

	const char * szConstCharX = "const char *";
	char const * szCharConstX = "char const *";
	char * const szCharXConst = "char * const";
//	const char const * szConstCharConstX = "const char const *";//duplicate 'const'
	const char * const szConstCharXConst = "const char * const";//duplicate 'const'
//	szConstCharX[0] = '3';//error: assignment of read-only location '* szConstChar'
	szConstCharX = NULL;//correct
//	szCharConstX[0] = '3';//error: assignment of read-only location '* szConstChar'
	szCharConstX = NULL;//correct
	szCharXConst[0] = '3';//correct
//	szCharXConst = NULL;// error: assignment of read-only variable 'szCharXConst'
//	szConstCharXConst[0] = '3';//error: assignment of read-only location '*(const char*)szConstCharXConst'
//	szConstCharXConst = NULL;//error: assignment of read-only variable 'szConstCharXConst'
	cout << "const char * szConstChar is " << szConstCharX << endl;
};

/**
 * new[] is by ascending order, delete[] is by descending order. 
 * */
void TestingClass::testNewDelete() {
//	TestingClass *testing = NULL;
//	testing = new TestingClass[8];//new self construction method can't be invoked in self member function ? 
	TestSingleInheritLvl1 *testing = NULL;
	testing = new TestSingleInheritLvl1[8];
	delete[] testing;
}

/**
 * 3
 * The function also tests the size of inherited classes. 
 * It is not necessary to add "static" for static member method in definition.
 * */
void TestingClass::testSingleInherit() {
	//p1lvl1 the 1st number is class name, and 2nd number is instantiated content.
	TestSingleInheritLvl1 *p1lvl1, *p1lvl2, *p1lvl3;
	TestSingleInheritLvl2 *p2lvl3;
	TestSingleInheritLvl3 *p3lvl3;

	const short *capacities;

	cout << "The size of TestSingleInheritLvl1 is " << sizeof(TestSingleInheritLvl1) << endl;
	cout << "The size of TestSingleInheritLvl2 is " << sizeof(TestSingleInheritLvl2) << endl;
	cout << "The size of TestSingleInheritLvl3 is " << sizeof(TestSingleInheritLvl3) << endl;
	
	cout << "Initialising p1lvl1 ... " << endl;
	p1lvl1 = new TestSingleInheritLvl1();
	cout << "Complete initialising p1lvl1 ... " << endl;

	cout << "Initialising p1lvl2 ... " << endl;
	p1lvl2 = new TestSingleInheritLvl2();
	cout << "Complete initialising p1lvl2 ... " << endl;

	cout << "Initialising p1lvl3 ... " << endl;
	p1lvl3 = new TestSingleInheritLvl3();
	cout << "Complete initialising p1lvl3 ... " << endl;
	
	p2lvl3 = (TestSingleInheritLvl2*)p1lvl3;
	p3lvl3 = (TestSingleInheritLvl3*)p1lvl3;
	cout << "The value of private id in TestSingleInheritLvl2 is " << p2lvl3->getID() << endl;
	cout << "The value of protected number in TestSingleInheritLvl2 is " << p2lvl3->getProtectedNumber() << endl;
	cout << "The value of private id in TestSingleInheritLvl3 is " << p3lvl3->getID() << endl;
	cout << "The value of protected number in TestSingleInheritLvl3 is " << p3lvl3->getProtectedNumber() << endl;
	p2lvl3->setProtectedNumber(-5);
	p3lvl3->setProtectedNumber(-6);
	cout << "After the 1st assigning, the value of protected number in TestSingleInheritLvl2 is " << p2lvl3->getProtectedNumber() << endl;
	cout << "After the 1st assigning, the value of protected number in TestSingleInheritLvl3 is " << p3lvl3->getProtectedNumber() << endl;
	//It there is no attack method in TestSingleInheritLvl3, it prompts error at runtime when calling in TestSingleInheritLvl1 & 2.
	//However, it is ok when calling in TestSingleInheritLvl3. Strange. Maybe, it is better to add this virtual function in top class. 
	//Whyyyyyyyyyyyyyy?????? Well, perhaps, this method is not compiled and it is ok now. 
	cout << "TestSingleInheritLvl1 is attacking " << p1lvl3->attack() << endl;
	cout << "TestSingleInheritLvl2 is attacking " << p2lvl3->attack() << endl;
	cout << "TestSingleInheritLvl3 is attacking " << p3lvl3->attack() << endl;
	p2lvl3=NULL;
	p3lvl3=NULL;

	capacities = p1lvl3->getCapacities();//if no const, error: invalid conversion from 'const short int*' to 'short int*' [-fpermissive]
	cout << "The address of capacities is " << capacities << endl;

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
	TestMultiInheritLvl3 *p3clvl3=NULL;

	cout << "The size of TestMultiInheritLvl1 is " << sizeof(TestMultiInheritLvl1) << endl;
	cout << "The size of TestMultiInheritLvl1A is " << sizeof(TestMultiInheritLvl1A) << endl;
	cout << "The size of TestMultiInheritLvl2A is " << sizeof(TestMultiInheritLvl2A) << endl;
	cout << "The size of TestMultiInheritLvl2B is " << sizeof(TestMultiInheritLvl2B) << endl;
	cout << "The size of TestMultiInheritLvl2C is " << sizeof(TestMultiInheritLvl2C) << endl;
	cout << "The size of TestMultiInheritLvl3 is " << sizeof(TestMultiInheritLvl3) << endl;
	
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

	p3clvl3=(TestMultiInheritLvl3 *)p1alvl3;
	p2blvl3->attack();
	p2clvl3->attack();
	//if member function attack is declared in both TestMultiInheritLvl2B & TestMultiInheritLvl2C, 
	//"request for member 'attack' is ambiguous"
//	p3clvl3->attack();
	p3clvl3->TestMultiInheritLvl2B::attack();//it is OK
	p3clvl3->TestMultiInheritLvl2C::attack();//it is OK
	p3clvl3=NULL;
	
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

void TestingClass::testVirSingleInherit() {
	TestVirSingleInheritLvl1 *p1lvl1, *p1lvl2, *p1lvl3;
	cout << "The size of TestVirSingleInheritLvl1 is " << sizeof(TestVirSingleInheritLvl1) << endl;
	cout << "The size of TestVirSingleInheritLvl2 is " << sizeof(TestVirSingleInheritLvl2) << endl;
	cout << "The size of TestVirSingleInheritLvl3 is " << sizeof(TestVirSingleInheritLvl3) << endl;
	
	cout << "Initialising p1lvl1 ... " << endl;
	p1lvl1 = new TestVirSingleInheritLvl1();
	cout << "Complete initialising p1lvl1 ... " << endl;
	
	cout << "Initialising p1lvl2 ... " << endl;
	p1lvl2 = new TestVirSingleInheritLvl2();
	cout << "Complete initialising p1lvl2 ... " << endl;
	
	cout << "Initialising p1lvl3 ... " << endl;
	p1lvl3 = new TestVirSingleInheritLvl3();
	cout << "Complete initialising p1lvl3 ... " << endl;
	
	cout << "Destorying p1lvl1 p1lvl2 p1lvl3... " << endl;
	delete p1lvl1;p1lvl1=NULL;
	delete p1lvl2;p1lvl2=NULL;
	delete p1lvl3;p1lvl3=NULL;
	cout << "Complete destorying p1lvl1 p1lvl2 p1lvl3 ... " << endl;
}

void TestingClass::testVirMultiInherit() {
	TestVirMultiInheritLvl1 *p1lvl3=NULL;
	TestVirMultiInheritLvl2A *p2alvl3=NULL;
	TestVirMultiInheritLvl2B *p2blvl3=NULL;
	TestVirMultiInheritLvl2C *p2clvl3=NULL;
	TestVirMultiInheritLvl3 *p3lvl3=NULL;
	
	cout << "The size of TestVirMultiInheritLvl1 is " << sizeof(TestVirMultiInheritLvl1) << endl;
	cout << "The size of TestVirMultiInheritLvl2A is " << sizeof(TestVirMultiInheritLvl2A) << endl;
	cout << "The size of TestVirMultiInheritLvl2B is " << sizeof(TestVirMultiInheritLvl2B) << endl;
	cout << "The size of TestVirMultiInheritLvl2C is " << sizeof(TestVirMultiInheritLvl2C) << endl;
	cout << "The size of TestVirMultiInheritLvl3 is " << sizeof(TestVirMultiInheritLvl3) << endl;
	
	cout << "Initialising p3lvl3 ... " << endl;
	p3lvl3 = new TestVirMultiInheritLvl3();
	cout << "Complete initialising p3lvl3 ... " << endl;
	
	p1lvl3=p3lvl3;
	p2alvl3=p3lvl3;
	p2blvl3=p3lvl3;
	p2clvl3=p3lvl3;
	
	p1lvl3=NULL;
	p2alvl3=NULL;
	p2blvl3=NULL;
	p2clvl3=NULL;
	
	cout << "Destorying p1lvl1 all the objects... " << endl;
	delete p3lvl3;p3lvl3 = NULL;
	cout << "Complete destorying all the objects ... " << endl;
}

void TestingClass::testConst()
{
	const string strTest("This is a test string.");
}
