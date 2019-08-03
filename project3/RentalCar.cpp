//
// Name: RentalCar.cpp
// Purpose: contains definitions of RentalCar class functions
//
#include <iostream>
#include "RentalCar.h"
#include "proj3.h"

const int DFLT_YEAR = 2000;
const char * DFLT_MAKE = "Generic";
const char * DFLT_MODEL = "Car";
const float DFLT_PRICE = 100.0f;

// default constructor
RentalCar::RentalCar() {
	setYear(DFLT_YEAR);
	setMake(DFLT_MAKE);
	setModel(DFLT_MODEL);
	setPrice(DFLT_PRICE);
	setAvailable(false);
}

// parameterized constructor
RentalCar::RentalCar(int year, const char * make, const char * model, float price, bool available) {
	setYear(year);
	setMake(make);
	setModel(model);
	setPrice(price);
	setAvailable(available);
}

void RentalCar::print(std::ostream & out) const {
	out << m_year << " " << m_make << " "
		<< m_model << ", $" << m_price
		<< " per day, Available: "
		<< std::boolalpha << m_available
		<< std::endl;
}

float RentalCar::estimateCost(int days) const {
	return m_price * days;	
}

//
// getter functions for all the private members of RentalCar
//

int RentalCar::getYear() const {
	return m_year;
}

// copies string into parameter cstring so user does not have access to actual string
void RentalCar::getMake(char * cstring) const {
	myStringCopy(cstring, m_make);
}

// copies string into parameter cstring so user does not have access to actual string
void RentalCar::getModel(char * cstring) const {
	myStringCopy(cstring, m_model);
}

float RentalCar::getPrice() const {
	return m_price;
}

bool RentalCar::getAvailable() const {
	return m_available;
}

//
// setter functions for all the private members of RentalCar
//

void RentalCar::setYear(int year) {
	m_year = year;
}

void RentalCar::setMake(const char * make) {
	myStringCopy(m_make, make);
}

void RentalCar::setModel(const char * model) {
	myStringCopy(m_model, model);
}

void RentalCar::setPrice(float price) {
	m_price = price;
}

void RentalCar::setAvailable(bool available) {
	m_available = available;
}
