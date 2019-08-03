//
// Name: Car.cpp
// Author: Logan K. Leavitt
// Purpose: definitions of derived class Car's member functions
//
#include <iostream>
#include <cstring>
#include "Car.h"

// Default Constructor
Car::Car() 
	: Vehicle()
	, m_throttle(DFLT_THROTTLE) 
{
	std::cout << "Car #" << m_vin
		<< ": Default-ctor" << std::endl;
}

// Parameterized Constructor
Car::Car(const char * plates, int vin, float * lla)
	: Vehicle(vin, lla)
	, m_throttle(DFLT_THROTTLE) 
{
	std::cout << "Car #" << m_vin
		<< ": Parameterized-ctor" << std::endl;

	setPlates(plates);
}

// Copy constructor
Car::Car(const Car & car)
	: Vehicle(car)
	, m_throttle(car.m_throttle)
{
	std::cout << "Car #" << m_vin
		<< ": Copy-ctor" << std::endl;

	setPlates(car.m_plates);
}

// Destructor
Car::~Car() {
	std::cout << "Car #" << m_vin << ": Dtor" << std::endl;
}

// assignment operator
const Car & Car::operator=(const Car & rhs) {
	Vehicle::operator=(rhs);

	setPlates(rhs.m_plates);
	m_throttle = rhs.m_throttle;

	return *this;
}

// insertion operator
std::ostream & operator<<(std::ostream & os, const Car & car) {
	os << "Car #" << car.m_vin
		<< " Plates: " << car.m_plates
		<< ", Throttle: " << car.m_throttle
		<< " @ [" << car.m_lla[LAT]
		<< ", " << car.m_lla[LON]
		<< ", " << car.m_lla[ALT]
		<< "]" << std::endl;

	return os;
}

//
// Getters
//

const char * Car::getPlates() const {
	return m_plates;
}

int Car::getThrottle() const {
	return m_throttle;
}

// 
// Setters
//

void Car::setPlates(const char * plates) {
	strcpy(m_plates, plates);
}

// assigns param throttle to m_throttle
void Car::drive(int throttle) {
	m_throttle = throttle;
}

// calls drive with throttle of 75 and changes the car's location to lla
void Car::move(float * lla) {
	std::cout << "Car #" << m_vin
		<< ": DRIVE to destination, with throttle @ 75"
		<< std::endl;

	drive(75);
	setLLA(lla);
}
