/*
 * TestSingleInheritLvl2.h
 *
 *  Created on: Oct 21, 2016
 *      Author:
 */

#ifndef TESTSINGLEINHERITLVL2_H_
#define TESTSINGLEINHERITLVL2_H_

#include "TestSingleInheritLvl1.h"

namespace itachi {

class TestSingleInheritLvl2: public TestSingleInheritLvl1 {
public:
	TestSingleInheritLvl2();
	virtual ~TestSingleInheritLvl2();
};

} /* namespace itachi */

#endif /* TESTSINGLEINHERITLVL2_H_ */
