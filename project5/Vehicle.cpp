//
// Name: Vehicle.cpp
// Author: Logan K. Leavitt
// Purpose: define base class Vehicle's member functions
//
#include <iostream>
#include "Vehicle.h"

int Vehicle::s_idgen = 1;

// Default Constructor
Vehicle::Vehicle() : m_vin(s_idgen++) {
	std::cout << "Vehicle #" << m_vin
		<< ": Default-ctor" << std::endl;
}

// Parameterized Constructor
Vehicle::Vehicle(int vin, float * lla) : m_vin((vin < s_idgen) ? s_idgen : vin) {
	std::cout << "Vehicle #" << m_vin
		<< ": Parameterized-ctor" << std::endl;

	if (vin > s_idgen) {
		s_idgen = vin;
	}
	s_idgen++;

	setLLA(lla);
}

// Copy Constructor
Vehicle::Vehicle(const Vehicle & v) : m_vin(s_idgen++) {
	std::cout << "Vehicle #" << m_vin
		<< ": Copy-ctor" << std::endl;

	setLLA(v.getLLA());
}

// Destructor
Vehicle::~Vehicle() {
	std::cout << "Vehicle #" << m_vin
		<< ": Dtor" << std::endl;
}

// assignment operator
const Vehicle & Vehicle::operator=(const Vehicle & rhs) {
	std::cout << "Vehicle #" << m_vin
		<< ": Assignment" << std::endl;

	setLLA(rhs.getLLA());

	return *this;
}

// insertion operator
std::ostream & operator<<(std::ostream & os, const Vehicle & v) {
	os << "Vehicle #" << v.m_vin << " @ ["
		<< v.m_lla[LAT] << ", "
		<< v.m_lla[LON] << ", "
		<< v.m_lla[ALT] << "]" << std::endl;

	return os;
}

//
// Getters
//

const float * Vehicle::getLLA() const {
	return m_lla;
}

int Vehicle::getVIN() const {
	return m_vin;
}

//
// Setters
//

void Vehicle::setLLA(const float * lla) {
	for (int i = 0; i < 3; i++, lla++) {
		m_lla[i] = *lla;
	}
}

// move member function, no defined functionality for Vehicle base class
// to be overloaded and defined in derived classes
void Vehicle::move(float * lla) const {
	std::cout << "Vehicle #" << m_vin
		<< ": CANNOT MOVE - I DON'T KNOW HOW"
		<< std::endl;
}

// static member setter
int Vehicle::getIdgen() {
	return s_idgen;
}
