//
// Name: Car.cpp
// Author: Logan K. Leavitt
// Purpose: defines methods of derived class Car
//
#include <iostream>
#include "Car.h"

//
// Ctors/Dtor
//

Car::Car() : Vehicle() , m_throttle(DFLT_THROTTLE) {
	std::cout << "Car: Default-ctor" << std::endl;
}

Car::Car(const float * lla) : Vehicle(lla) , m_throttle(DFLT_THROTTLE) {
	std::cout << "Car: Parametrized-ctor" << std::endl;
}

Car::Car(const Car & other) : Vehicle(other) , m_throttle(other.m_throttle) {
	std::cout << "Car: Copy-ctor" << std::endl;
}

Car::~Car() {
	std::cout << "Car: Dtor" << std::endl;
}

// assignment operator
const Car & Car::operator=(const Car & other) {
	Vehicle::operator=(other);
	std::cout << "Car: Assignment" << std::endl;

	m_throttle = other.m_throttle;

	return *this;
}

// 
// getter and setter
//

int Car::getThrottle() const {
	return m_throttle;
}

void Car::setThrottle(int throttle) {
	m_throttle = throttle;
}

// assigns throttle to m_throttle, used in Move
void Car::drive(int throttle) {
	setThrottle(throttle);
}

// prints message, calls drive with 75 and changes location
void Car::Move(const float * new_lla) {
	std::cout << "Car: DRIVE to destination, with throttle @ 75" << std::endl;

	drive(75);
	SetLLA(new_lla);
}

// virtual function used in operator<< to print
// specialized message
void Car::serialize(std::ostream & os) const {
	std::cout << "Car: Throttle: " << m_throttle << " @ ["
		<< m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2]
		<< "]" << std::endl;
}
