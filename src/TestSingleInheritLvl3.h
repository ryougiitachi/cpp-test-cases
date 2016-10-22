/*
 * TestSingleInheritLvl3.h
 *
 *  Created on: Oct 21, 2016
 *      Author:
 */

#ifndef TESTSINGLEINHERITLVL3_H_
#define TESTSINGLEINHERITLVL3_H_

#include "TestSingleInheritLvl2.h"

namespace itachi {

class TestSingleInheritLvl3: public TestSingleInheritLvl2 {
public:
	TestSingleInheritLvl3();
	virtual ~TestSingleInheritLvl3();
};

} /* namespace itachi */

#endif /* TESTSINGLEINHERITLVL3_H_ */

