/*
 * TestMultiInherit.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author:
 */

#include <iostream>
#include "TestMultiInherit.h"

using namespace std;

namespace itachi {

TestMultiInheritLvl1::TestMultiInheritLvl1() {
	cout << "The class TestMultiInheritLvl1 is constructing at " << this << endl;
}

TestMultiInheritLvl1::~TestMultiInheritLvl1() {
	cout << "The class TestMultiInheritLvl1 is destructing at " << this << endl;
}
//a member method can't be defined for > 1 time.
//TestMultiInheritLvl1::TestMultiInheritLvl1() {
//	cout << "The class TestMultiInheritLvl1 is constructing at " << this << endl;
//}

TestMultiInheritLvl1A::TestMultiInheritLvl1A() {
	cout << "The class TestMultiInheritLvl1A is constructing at " << this << endl;
}

TestMultiInheritLvl1A::~TestMultiInheritLvl1A() {
	cout << "The class TestMultiInheritLvl1A is destructing at " << this << endl;
}

TestMultiInheritLvl2A::TestMultiInheritLvl2A() {
	cout << "The class TestMultiInheritLvl2A is constructing at " << this << endl;
}

TestMultiInheritLvl2A::~TestMultiInheritLvl2A() {
	cout << "The class TestMultiInheritLvl2A is destructing at " << this << endl;
}

TestMultiInheritLvl2B::TestMultiInheritLvl2B() {
	cout << "The class TestMultiInheritLvl2B is constructing at " << this << endl;
}

TestMultiInheritLvl2B::~TestMultiInheritLvl2B() {
	cout << "The class TestMultiInheritLvl2B is destructing at " << this << endl;
}

void TestMultiInheritLvl2B::attack() {
	cout << "TestMultiInheritLvl2B is attacking. " << endl;
}

TestMultiInheritLvl2C::TestMultiInheritLvl2C() {
	cout << "The class TestMultiInheritLvl2C is constructing at " << this << endl;
}

TestMultiInheritLvl2C::~TestMultiInheritLvl2C() {
	cout << "The class TestMultiInheritLvl2C is destructing at " << this << endl;
}

void TestMultiInheritLvl2C::attack() {
	cout << "TestMultiInheritLvl2C is attacking. " << endl;
}

TestMultiInheritLvl3::TestMultiInheritLvl3() {
	cout << "The class TestMultiInheritLvl3 is constructing at " << this << endl;
}

TestMultiInheritLvl3::~TestMultiInheritLvl3() {
	cout << "The class TestMultiInheritLvl3 is destructing at " << this << endl;
}

} /* namespace itachi */
