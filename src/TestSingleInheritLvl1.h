/*
 * TestSingleInheritLvl1.h
 *
 *  Created on: Oct 21, 2016
 *      Author:
 */

#ifndef TESTSINGLEINHERITLVL1_H_
#define TESTSINGLEINHERITLVL1_H_

namespace itachi {

class TestSingleInheritLvl1 {
private:
	short capacities[8];
public:
	static const int SINGLE_INHERIT_COUNT_CAPACITIES = 8;
public:
	TestSingleInheritLvl1();
	virtual ~TestSingleInheritLvl1();
	virtual int attack();

	const short *getCapacities() const;
};

} /* namespace itachi */

#endif /* TESTSINGLEINHERITLVL1_H_ */
