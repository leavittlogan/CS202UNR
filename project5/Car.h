//
// Name: Car.h
// Author: Logan K. Leavitt
// Purpose: declaration of derived Class Car
//
#ifndef CAR_H_
#define CAR_H_
#include <iostream>
#include "Vehicle.h"

const int PLATES_SIZE = 256;
const int DFLT_THROTTLE = 0;

class Car : public Vehicle {
	public:
		// Constructors/Destructor
		Car();
		Car(const char * plates, int vin, float * lla);
		Car(const Car & car);
		~Car();

		// operator overloads
		const Car & operator=(const Car & rhs);
		friend std::ostream & operator<<(std::ostream & os, const Car & car);

		// getters and setters
		const char * getPlates() const;
		int getThrottle() const;
		void setPlates(const char * plates);

		// car's move functionalities
		void drive(int throttle);
		void move(float * lla);

	private:
		char m_plates[PLATES_SIZE];
		int m_throttle;
};

#endif
