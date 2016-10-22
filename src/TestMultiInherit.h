/*
 * TestMultiInherit.h
 *
 *  Created on: Oct 21, 2016
 *      Author:
 */

#ifndef TESTMULTIINHERIT_H_
#define TESTMULTIINHERIT_H_

namespace itachi {

class TestMultiInheritLvl1 {
public:
	//However, TestMultiInheritLvl1 is not base class for TestMultiInheritLvl3 ??????
	TestMultiInheritLvl1();
	virtual ~TestMultiInheritLvl1();
};

class TestMultiInheritLvl1A {
public:
	//However, TestMultiInheritLvl1 is not base class for TestMultiInheritLvl3 ??????
	TestMultiInheritLvl1A();
	virtual ~TestMultiInheritLvl1A();
};

class TestMultiInheritLvl2A: public TestMultiInheritLvl1, public TestMultiInheritLvl1A {
public:
	TestMultiInheritLvl2A();
	virtual ~TestMultiInheritLvl2A();
};

class TestMultiInheritLvl2B: public TestMultiInheritLvl1 {
public:
	TestMultiInheritLvl2B();
	virtual ~TestMultiInheritLvl2B();
};

class TestMultiInheritLvl2C: public TestMultiInheritLvl1 {
public:
	TestMultiInheritLvl2C();
	virtual ~TestMultiInheritLvl2C();
};

//TestMultiInheritLvl1 can't be direct base for TestMultiInheritLvl3 due to all the
//TestMultiInheritLvl2A/B/C basic on TestMultiInheritLvl1 ?
class TestMultiInheritLvl3: public TestMultiInheritLvl2A,
		public TestMultiInheritLvl2B, public TestMultiInheritLvl2C {
public:
	//When constructing, the instantiated object will construct from the most basic class(It is
	//TestMultiInheritLvl1 for this example) by inherited order.
	//TestMultiInheritLvl1=>TestMultiInheritLvl2A, TestMultiInheritLvl1=>TestMultiInheritLvl2B,
	//TestMultiInheritLvl1=>TestMultiInheritLvl2C=>TestMultiInheritLvl3
	TestMultiInheritLvl3();
	//When destructing, in return, above steps are reserved including inherited order.
	virtual ~TestMultiInheritLvl3();
};

} /* namespace itachi */

#endif /* TESTMULTIINHERIT_H_ */

