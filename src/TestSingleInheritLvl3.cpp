/*
 * TestSingleInheritLvl3.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author:
 */

#include <iostream>
#include "TestSingleInheritLvl3.h"

using namespace std;

namespace itachi {

TestSingleInheritLvl3::TestSingleInheritLvl3() {
	cout << "There is TestSingleInheritLvl3 constructing " << this << endl;
}

TestSingleInheritLvl3::~TestSingleInheritLvl3() {
	cout << "There is TestSingleInheritLvl3 destructing " << this << endl;
}

} /* namespace itachi */
