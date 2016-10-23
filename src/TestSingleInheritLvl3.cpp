/*
 * TestSingleInheritLvl3.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author:
 */

#include <iostream>
#include "TestSingleInheritLvl2.h"
#include "TestSingleInheritLvl3.h"

using namespace std;

namespace itachi {

TestSingleInheritLvl3::TestSingleInheritLvl3() {
	this->id = -3;
	this->protectedNumber = -3;
	cout << "There is TestSingleInheritLvl3 constructing " << this << endl;
}

TestSingleInheritLvl3::~TestSingleInheritLvl3() {
	cout << "There is TestSingleInheritLvl3 destructing " << this << endl;
}

int TestSingleInheritLvl3::getID () const // const is required for definition
{
	return id;
}

void TestSingleInheritLvl3::setID (int id)
{
	this->id = id;
}

int TestSingleInheritLvl3::getProtectedNumber () const
{
//	return protectedNumber;
//	return TestSingleInheritLvl2::getProtectedNumber();	//no error
	return TestSingleInheritLvl2::protectedNumber;
}

void TestSingleInheritLvl3::setProtectedNumber (int protectedNumber)
{
	this->protectedNumber = protectedNumber;
}

/**
 * 
 * 
int TestSingleInheritLvl3::attack() {
	return -3;
//	return TestSingleInheritLvl2::attack();//no error, TestSingleInheritLvl2::attack() value will be returned. 
}*/

} /* namespace itachi */
