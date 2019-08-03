//
// Name: Vehicle.cpp
// Author: Logan K. Leavitt
// Purpose: define functions of abstract class Vehicle
//
#include <iostream>
#include "Vehicle.h"

//
// Ctors/Dtor
//

Vehicle::Vehicle() {
	std::cout << "Vehicle: Default-ctor" << std::endl;
}

Vehicle::Vehicle(const float * lla) {
	std::cout << "Vehicle: Parametrized-ctor" << std::endl;

	SetLLA(lla);
}

Vehicle::Vehicle(const Vehicle & other) {
	std::cout << "Vehicle: Copy-ctor" << std::endl;

	SetLLA(other.m_lla);
}

Vehicle::~Vehicle() {
	std::cout << "Vehicle: Dtor" << std::endl;
}

//
// Operator overloads
//

const Vehicle & Vehicle::operator=(const Vehicle & other) {
	std::cout << "Vehicle: Assignment" << std::endl;

	SetLLA(other.m_lla);

	return *this;
}

std::ostream & operator<<(std::ostream & os, const Vehicle & v) {
	v.serialize(os);

	return os;
}

//
// getter and setter for m_lla
//

const float * Vehicle::GetLLA() const {
	return m_lla;
}

void Vehicle::SetLLA(const float * lla) {
	for (int i = 0; i < 3; i++) m_lla[i] = *(lla++);
}

//
// virtual method used in operator<< to
// print different message to terminal depending on
// type of object
//

void Vehicle::serialize(std::ostream & os) const {
	os << "Vehicle @ [" << m_lla[0] << ", " << m_lla[1]
		<< ", " << m_lla[2] << "]" << std::endl;
}
