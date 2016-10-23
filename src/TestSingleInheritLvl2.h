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
private:
	int id;
protected:
	int protectedNumber;
public:
	TestSingleInheritLvl2();
	virtual ~TestSingleInheritLvl2();

	int getID () const;
	
	void setID (int id);
	
	int getProtectedNumber () const;
	
	void setProtectedNumber (int number);
	
	virtual int attack();
};

} /* namespace itachi */

#endif /* TESTSINGLEINHERITLVL2_H_ */
