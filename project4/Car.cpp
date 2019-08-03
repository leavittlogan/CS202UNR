//
// Name: Car.cpp
// Author: Logan K. Leavitt
// Purpose: contains definitions of Car's member functions
//
#include "proj4.h"
#include "Car.h"
#include "Sensor.h"

// Default Constructor
Car::Car() : Car(DFLT_MAKE, DFLT_MODEL, DFLT_YEAR, DFLT_PRICE, DFLT_SENSORS) {}

// Paramaterized Constructor
Car::Car(const char * make, const char * model, int year, float baseprice, const char * const * sensorTypes)
	: m_year(year), m_baseprice(baseprice), m_available(true), m_num_sensors(0)
{
	setMake(make);
	setModel(model);

	for (int i = 0; i < MAX_SENSORS; i++, sensorTypes++) {
		*this + Sensor(*sensorTypes);
	}

	updatePrice();
	
	setOwner("");
}

// Copy Constructor
Car::Car(const Car & car)
	: m_year(car.m_year), m_baseprice(car.m_baseprice)
	, m_num_sensors(0), m_available(car.m_available)
{
	setMake(car.m_make);
	setModel(car.m_model);

	for (int i = 0; i < MAX_SENSORS; i++) {
		*this + car.getSensor(i);
	}

	updatePrice();

	setOwner(car.getOwner());
}

//
// Getters
//

const char * Car::getMake() const {
	return m_make;
}

const char * Car::getModel() const {
	return m_model;
}

int Car::getYear() const {
	return m_year;
}

const Sensor & Car::getSensor(unsigned int index) const {
	return *(m_sensors + index);
}

float Car::getBasePrice() const {
	return m_baseprice;
}

float Car::getFinalPrice() const {
	return m_finalprice;
}

bool Car::getAvailable() const {
	return m_available;
}

const char * Car::getOwner() const {
	return m_owner;
}

//
// Setters
//

void Car::setMake(const char * make) {
	myStringCopy(m_make, make);
}

void Car::setModel(const char * model) {
	myStringCopy(m_model, model);
}

void Car::setYear(int year) {
	m_year = year;
}

void Car::setBasePrice(float baseprice) {
	m_baseprice = baseprice;
}

void Car::setAvailable(bool available) {
	m_available = available;
}

void Car::setOwner(const char * owner) {
	myStringCopy(m_owner, owner);
}


// iterates through sensors and calculates finalprice (baseprice + sensors)
void Car::updatePrice() {
	float finalprice = m_baseprice;

	Sensor * ptr = m_sensors;
	for (int i = 0; i < MAX_SENSORS; i++, ptr++) {
		finalprice += ptr->getExtraCost();
	}

	m_finalprice = finalprice;
}

// prints Car data to terminal
void Car::print() const {
	std::cout << m_year << " " << m_make << " "
		<< m_model << " $"
		<< m_baseprice << " {";

	const Sensor * ptr = m_sensors;
	bool printedSensors = false;
	for (int i = 0; i < MAX_SENSORS; i++, ptr++) {
		if (myStringCompare(ptr->getType(), "none") != 0) {
			std::cout << ptr->getType() << " ";
			printedSensors = true;
		}
	}
	if (printedSensors) std::cout << '\b';

	std::cout << "} Available: " << std::boolalpha << m_available;

	if (!m_available) {
		std::cout << ", rented by " << m_owner;
	}

	std::cout << std::endl;
}

// estimates rental cost for a given number of days
float Car::estimateCost(int days) const {
	return m_finalprice * days;
}

// adds sensor to Car object if not already full
void Car::operator+(const Sensor & sensor) {
	if (m_num_sensors < MAX_SENSORS) {
		if (myStringCompare(sensor.getType(), "none") != 0) {
			*(m_sensors + m_num_sensors++) = sensor;
			updatePrice();
		}
	}
}

// adds owner to Car and sets m_available to false
void Car::operator+(const char * lessee) {
	if (m_available) {
		setOwner(lessee);
		m_available = false;
	}
}
