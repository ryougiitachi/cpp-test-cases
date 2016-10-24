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
	
	TestVirSingleInheritLvl3::TestVirSingleInheritLvl3 ()
	{
		cout << "There is TestVirSingleInheritLvl3 constructing " << this << endl;
	}

	TestVirSingleInheritLvl3::~TestVirSingleInheritLvl3 ()
	{
		cout << "There is TestVirSingleInheritLvl3 destructing " << this << endl;
	}

} /* namespace itachi */
