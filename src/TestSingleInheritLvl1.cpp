/*
 * TestSingleInheritLvl1.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author:
 */

#include <iostream>
#include "TestSingleInheritLvl1.h"

using namespace std;

namespace itachi {

TestSingleInheritLvl1::TestSingleInheritLvl1() {
	cout << "There is TestSingleInheritLvl1 constructing " << this << endl;
}

TestSingleInheritLvl1::~TestSingleInheritLvl1() {
	cout << "There is TestSingleInheritLvl1 destructing " << this << endl;
}

int TestSingleInheritLvl1::attack() {
	return -1;
}
} /* namespace itachi */

