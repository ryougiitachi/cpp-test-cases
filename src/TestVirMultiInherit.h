/*
 * TestVirMultiInherit.h
 *
 *  Created on: 2016Äê10ÔÂ23ÈÕ
 *      Author: 
 */

#ifndef TESTVIRMULTIINHERIT_H_
#define TESTVIRMULTIINHERIT_H_

namespace itachi
{
	class TestVirMultiInheritLvl1
	{
	public:
		TestVirMultiInheritLvl1 ();
		virtual ~TestVirMultiInheritLvl1 ();
	};

	class TestVirMultiInheritLvl2A: virtual public TestVirMultiInheritLvl1
	{
	public:
		TestVirMultiInheritLvl2A ();
		virtual ~TestVirMultiInheritLvl2A ();
	};

	class TestVirMultiInheritLvl2B: virtual public TestVirMultiInheritLvl1
	{
	public:
		TestVirMultiInheritLvl2B ();
		virtual ~TestVirMultiInheritLvl2B ();
	};

	class TestVirMultiInheritLvl2C: virtual public TestVirMultiInheritLvl1
	{
	public:
		TestVirMultiInheritLvl2C ();
		virtual ~TestVirMultiInheritLvl2C ();
	};

	class TestVirMultiInheritLvl3: virtual public TestVirMultiInheritLvl2A, 
			virtual public TestVirMultiInheritLvl2B, 
			virtual public TestVirMultiInheritLvl2C
	{
	public:
		TestVirMultiInheritLvl3 ();
		virtual ~TestVirMultiInheritLvl3 ();
	};
} /* namespace itachi */

#endif /* TESTVIRMULTIINHERIT_H_ */
