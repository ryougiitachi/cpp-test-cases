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

/**
 * const short TestSingleInheritLvl1::*getCapacities() const is err.
 * If so, error: non-member function 'const short int itachi::TestSingleInheritLvl1::*
 * itachi::getCapacities()' cannot have cv-qualifier
 * */
const short * TestSingleInheritLvl1::getCapacities() const {
	return this->capacities;
}

} /* namespace itachi */

