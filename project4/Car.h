//
// Name: Car.h
// Author: Logan K. Leavitt
// Purpose: declaration of Car Class
//
#ifndef CAR_H_
#define CAR_H_
#include <iostream>
#include "proj4.h"
#include "Sensor.h"

const int MAX_SENSORS = 3;

// Default values for Car Class
const char * const DFLT_MAKE = "Generic";
const char * const DFLT_MODEL = "Car";
const int DFLT_YEAR = 2000;
const float DFLT_PRICE = 0;
const char * const DFLT_SENSORS[] = {DFLT_TYPE, DFLT_TYPE, DFLT_TYPE};

class Car {
	public:
		// Default constructor
		Car();
		// paramaterized constructor
		// sensorTypes must be a pointer to a c-string array with three types
		Car(const char * make, const char * model, 
			int year, float baseprice, const char * const * sensorTypes);
		// copy constructor
		Car(const Car & car);

		// getters
		const char * getMake() const;
		const char * getModel() const;
		int getYear() const;
		const Sensor & getSensor(unsigned int index) const;
		float getBasePrice() const;
		float getFinalPrice() const;
		bool getAvailable() const;
		const char * getOwner() const;

		// setters
		void setMake(const char * make);
		void setModel(const char * model);
		void setYear(int year);
		void setBasePrice(float baseprice);
		void setAvailable(bool available);
		void setOwner(const char * owner);

		void updatePrice();
		void print() const;
		float estimateCost(int days) const;

		void operator+(const Sensor & sensor);
		void operator+(const char * lessee);

	private:
		char m_make[MAX_STR_SIZE];
		char m_model[MAX_STR_SIZE];
		int m_year;
		Sensor m_sensors[MAX_SENSORS];
		int m_num_sensors;
		float m_baseprice;
		float m_finalprice;
		bool m_available;
		char m_owner[MAX_STR_SIZE];
};

#endif
