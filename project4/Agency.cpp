//
// Name: Agency.cpp
// Author: Logan K. Leavitt
// Purpose: contains definitions of Agency functions
//
#include <iostream>
#include <fstream>
#include "Agency.h"
#include "Car.h"
#include "proj4.h"

// Default Constructor
Agency::Agency() : m_zipcode(DFLT_ZIPCODE) {
	setName(DFLT_NAME);
}

//
// Getters
//

const char * Agency::getName() const {
	return m_name;
}

int Agency::getZipcode() const {
	return m_zipcode;
}

//
// Setters
//

void Agency::setName(const char * name) {
	myStringCopy(m_name, name);
}

void Agency::setZipcode(int zipcode) {
	m_zipcode = zipcode;
}

// overload of [] operator, returns Car at index n of m_inventory
Car & Agency::operator[](unsigned int n) {
	return *(m_inventory + n);
}

// takes an input file and reads in data from that file
void Agency::readAllData(std::ifstream & file) {
	char name[MAX_STR_SIZE];
	int zipcode;
	file >> name >> zipcode;
	setName(name);
	setZipcode(zipcode);

	int year;
	char make[MAX_STR_SIZE], model[MAX_STR_SIZE], 
		sensor[MAX_STR_SIZE], owner[MAX_STR_SIZE];
	float price;
	bool available;


	Car * ptr = m_inventory;
	for (int i = 0; i < NUM_CARS; i++, ptr++) {
		file >> year >> make >> model >> price;
		ptr->setYear(year);
		ptr->setMake(make);
		ptr->setModel(model);
		ptr->setBasePrice(price);
		
		file.ignore(256, '{');
		bool done = false;
		while (!done) {
			file >> sensor;
			if (*(sensor + myStringLength(sensor) - 1) == '}') {
				*(sensor + myStringLength(sensor) - 1) = '\0';
				done = true;
			}
			*ptr + Sensor(sensor);
		}
		file.ignore();

		file >> available;
		if (!available) {
			file >> owner;
			*ptr + owner;
		}
	}
}

// prints agency info and all its cars
void Agency::printAllData() const {
	std::cout << std::endl << m_name << " " << m_zipcode << std::endl;

	const Car * ptr = m_inventory;
	for (int i = 0; i < NUM_CARS; i++, ptr++) {
		ptr->print();
	}
}

// prints agency info and only the available cars
void Agency::printAvailableCars() const {
	std::cout << std::endl << m_name << " " << m_zipcode << std::endl;

	const Car * ptr = m_inventory;
	for (int i = 0; i < NUM_CARS; i++, ptr++) {
		if (ptr->getAvailable()) {
			ptr->print();
		}
	}
}
