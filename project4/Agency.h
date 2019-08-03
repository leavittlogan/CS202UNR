//
// Name: Agency.h
// Author: Logan K. Leavitt
// Purpose: contains declarations of Agency class
//
#ifndef AGENCY_H_
#define AGENCY_H_
#include <iostream>
#include "proj4.h"
#include "Car.h"

// constants and default values for agency class
const int NUM_CARS = 5;
const char * const DFLT_NAME = "Agency";
const int DFLT_ZIPCODE = 11111; 

class Agency {
	public:
		// Default Constructor
		Agency();

		// getters
		const char * getName() const;
		int getZipcode() const;

		// setters
		void setName(const char * name);
		void setZipcode(int zipcode);

		Car & operator[](unsigned int n);

		void readAllData(std::ifstream & file);
		void printAllData() const;
		void printAvailableCars() const;

	private:
		char m_name[MAX_STR_SIZE];
		int m_zipcode;
		Car m_inventory[NUM_CARS];
};

#endif
