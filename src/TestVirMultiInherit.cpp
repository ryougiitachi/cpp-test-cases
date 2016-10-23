/*
 * TestVirMultiInherit.cpp
 *
 *  Created on: 2016Äê10ÔÂ23ÈÕ
 *      Author: 
 */

#include <iostream>
#include "TestVirMultiInherit.h"

using namespace std;

namespace itachi
{

	TestVirMultiInheritLvl1::TestVirMultiInheritLvl1 ()
	{
		cout << "There is TestVirMultiInheritLvl1 constructing " << this << endl;
	}
	
	TestVirMultiInheritLvl1::~TestVirMultiInheritLvl1 ()
	{
		cout << "There is TestVirMultiInheritLvl1 destructing " << this << endl;
	}

	TestVirMultiInheritLvl2A::TestVirMultiInheritLvl2A ()
	{
		cout << "There is TestVirMultiInheritLvl2A constructing " << this << endl;
	}
	
	TestVirMultiInheritLvl2A::~TestVirMultiInheritLvl2A ()
	{
		cout << "There is TestVirMultiInheritLvl2A destructing " << this << endl;
	}

	TestVirMultiInheritLvl2B::TestVirMultiInheritLvl2B ()
	{
		cout << "There is TestVirMultiInheritLvl2B constructing " << this << endl;
	}
	
	TestVirMultiInheritLvl2B::~TestVirMultiInheritLvl2B ()
	{
		cout << "There is TestVirMultiInheritLvl2B destructing " << this << endl;
	}

	TestVirMultiInheritLvl2C::TestVirMultiInheritLvl2C ()
	{
		cout << "There is TestVirMultiInheritLvl2C constructing " << this << endl;
	}
	
	TestVirMultiInheritLvl2C::~TestVirMultiInheritLvl2C ()
	{
		cout << "There is TestVirMultiInheritLvl2C destructing " << this << endl;
	}

	TestVirMultiInheritLvl3::TestVirMultiInheritLvl3 ()
	{
		cout << "There is TestVirMultiInheritLvl3 constructing " << this << endl;
	}
	
	TestVirMultiInheritLvl3::~TestVirMultiInheritLvl3 ()
	{
		cout << "There is TestVirMultiInheritLvl3 destructing " << this << endl;
	}

} /* namespace itachi */
