/*
 * TestSingleInheritLvl2.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author:
 */

#include <iostream>
#include "TestSingleInheritLvl2.h"

using namespace std;

namespace itachi {

TestSingleInheritLvl2::TestSingleInheritLvl2() {
	this->id = -2;
	this->protectedNumber = -2;
	cout << "There is TestSingleInheritLvl2 constructing " << this << endl;
}

TestSingleInheritLvl2::~TestSingleInheritLvl2() {
	cout << "There is TestSingleInheritLvl2 destructing " << this << endl;
}

int TestSingleInheritLvl2::getID () const // const is required for definition
{
	return id;
}

void TestSingleInheritLvl2::setID (int id)
{
	this->id = id;
}

int TestSingleInheritLvl2::getProtectedNumber () const
{
	return protectedNumber;
}

void TestSingleInheritLvl2::setProtectedNumber (int protectedNumber)
{
	this->protectedNumber = protectedNumber;
}

int TestSingleInheritLvl2::attack() {
	return -2;
}
} /* namespace itachi */

