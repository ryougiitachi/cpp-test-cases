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
	
	/**
	 * 1
	 * */
	static void testBasicDataType();

	/**
	 * 2
	 * */
	static void testNewDelete();

	/**
	 * 3
	 * */
	static void testSingleInherit();

	/**
	 * 4
	 * */
	static void testMultiInherit();

	/**
	 * 5
	 * */
	static void testVirSingleInherit();

	/**
	 * 6
	 * */
	static void testVirMultiInherit();

	/**
	 * 7
	 * */
	static void testArgumentsByCRegex(int argc, char **argv);

	/**
	 * 8
	 * */
	static void testArgumentsByCppRegex(int argc, char **argv);

	/**
	 * 9
	 * */
	static void testArgumentsByBoostRegex(int argc, char **argv);

	/**
	 * 10
	 * */
	static void testCout();

	/**
	 * 11
	 * */
	static void testException();
};

#endif /* TESTINGCLASS_H_ */
