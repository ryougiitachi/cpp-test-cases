/*
 * TestVirSingleInherit.h
 *
 *  Created on: 2016Äê10ÔÂ22ÈÕ
 *      Author: 
 */

#ifndef TESTVIRSINGLEINHERIT_H_
#define TESTVIRSINGLEINHERIT_H_

namespace itachi
{
	class TestVirSingleInheritLvl1
	{
	public:
		TestVirSingleInheritLvl1 ();
		virtual ~TestVirSingleInheritLvl1 ();
	};

	class TestVirSingleInheritLvl2: virtual public TestVirSingleInheritLvl1 
	{
	public:
		TestVirSingleInheritLvl2 ();
		virtual ~TestVirSingleInheritLvl2 ();
	};

	class TestVirSingleInheritLvl3: virtual public TestVirSingleInheritLvl2 
	{
	public:
		TestVirSingleInheritLvl3 ();
		virtual ~TestVirSingleInheritLvl3 ();
	};
} /* namespace itachi */

#endif /* TESTVIRSINGLEINHERIT_H_ */
