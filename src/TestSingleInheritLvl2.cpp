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
	cout << "There is TestSingleInheritLvl2 constructing " << this << endl;
}

TestSingleInheritLvl2::~TestSingleInheritLvl2() {
	cout << "There is TestSingleInheritLvl2 destructing " << this << endl;
}

} /* namespace itachi */

