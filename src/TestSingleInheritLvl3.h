/*
 * TestSingleInheritLvl3.h
 *
 *  Created on: Oct 21, 2016
 *      Author:
 */

#ifndef TESTSINGLEINHERITLVL3_H_
#define TESTSINGLEINHERITLVL3_H_

#include "TestSingleInheritLvl2.h"
#include "TestSingleInheritLvl3.h"

namespace itachi {

class TestSingleInheritLvl3: public TestSingleInheritLvl2 {
private:
	int id;
protected:
	int protectedNumber;//member variable with the same name and data type as its super class is OK in C++?????? Of course, seemingly. 
public:
	TestSingleInheritLvl3();
	virtual ~TestSingleInheritLvl3();

	int getID () const;
	
	void setID (int id);
	
	int getProtectedNumber () const;
	
	void setProtectedNumber (int number);
	
//	virtual int attack();//In this case, whether or not to add virtual won't take effect on result. 
};

} /* namespace itachi */

#endif /* TESTSINGLEINHERITLVL3_H_ */

