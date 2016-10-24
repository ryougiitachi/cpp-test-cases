/*
 * TestVirSingleInherit.cpp
 *
 *  Created on: 2016Äê10ÔÂ22ÈÕ
 *      Author: 
 */

#include <iostream>
#include "TestVirSingleInherit.h"

using namespace std;

namespace itachi
{
	
	TestVirSingleInheritLvl1::TestVirSingleInheritLvl1 ()
	{
		this->id = -1;
		this->protectedNumber = -1;
		this->publicNumber = -1;
		cout << "There is TestVirSingleInheritLvl1 constructing " << this << endl;
	}

	TestVirSingleInheritLvl1::~TestVirSingleInheritLvl1 ()
	{
		cout << "There is TestVirSingleInheritLvl1 destructing " << this << endl;
	}

	int TestVirSingleInheritLvl1::getProtectedNumber() const {
		return protectedNumber;
	}

	void TestVirSingleInheritLvl1::setProtectedNumber(int protectedNumber) {
		this->protectedNumber = protectedNumber;
	}
	
	TestVirSingleInheritLvl2::TestVirSingleInheritLvl2 ()
	{
		this->id = -1;
		this->protectedNumber = -1;
		this->publicNumber = -1;
		cout << "There is TestVirSingleInheritLvl2 constructing " << this << endl;
	}

	TestVirSingleInheritLvl2::~TestVirSingleInheritLvl2 ()
	{
		cout << "There is TestVirSingleInheritLvl2 destructing " << this << endl;
	}

	int TestVirSingleInheritLvl2::getProtectedNumber() const {
		return protectedNumber;
	}

	void TestVirSingleInheritLvl2::setProtectedNumber(int protectedNumber) {
		this->protectedNumber = protectedNumber;
	}
	
	TestVirSingleInheritLvl3::TestVirSingleInheritLvl3 ()
	{
		cout << "There is TestVirSingleInheritLvl3 constructing " << this << endl;
	}

	TestVirSingleInheritLvl3::~TestVirSingleInheritLvl3 ()
	{
		cout << "There is TestVirSingleInheritLvl3 destructing " << this << endl;
	}

} /* namespace itachi */
