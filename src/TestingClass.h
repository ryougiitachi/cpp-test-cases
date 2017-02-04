/*
 * TestingClass.h
 *
 *  Created on: Sep 19, 2016
 *      Author:
 */

#ifndef TESTINGCLASS_H_
#define TESTINGCLASS_H_

class TestingClass {
private:
	int generalID;
	unsigned char reserved1[4];	// memory alignment depends on the order of members declerations.
	char generalSurname[16];
	char generalLastname[16];
	char generalZiname[16];
	long long birthDate;
	int lifetime;
	unsigned char reserved2[4];	// memory alignment depends on the order of members declerations.
//	short capacities[5];

public:
	TestingClass();
	TestingClass(int generalID);//int generalID=0 is error for declaration
	virtual ~TestingClass();

	/**
	 * To ensure development principle, which means this is a read-only (member) function. 
	 * */
	int getGeneralID() const {
		return generalID;
	}

	void setGeneralID(int generalID) {
		this->generalID = generalID;
	}

	const char* getGeneralLastname() const {
		return generalLastname;
	}

	const char* getGeneralSurname() const {
		return generalSurname;
	}

	const char* getGeneralZiname() const {
		return generalZiname;
	}

	long long getBirthDate() const {
		return birthDate;
	}

	void setBirthDate(long long birthDate) {
		this->birthDate = birthDate;
	}

	int getLifetime() const {
		return lifetime;
	}

	void setLifetime(int lifetime) {
		this->lifetime = lifetime;
	}
	/***
	const short *getCapacities() const {
		return capacities;
	}***/

	virtual int run() {return 0;}

	virtual int attack() {return 0;}
	
	static void testBasicDataType();
	
	static void testNewDelete();

	static void testSingleInherit();

	static void testMultiInherit();
	
	static void testVirSingleInherit();
	
	static void testVirMultiInherit();
	
	static void testConst();
};

#endif /* TESTINGCLASS_H_ */
