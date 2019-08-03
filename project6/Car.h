//
// Name: Car.h
// Author: Logan K. Leavitt
// Purpose: declaration of derived class Car
//
#ifndef CAR_H_
#define CAR_H_

#include <iostream>
#include "Vehicle.h"

const int DFLT_THROTTLE = 0;

class Car : public Vehicle {
	public:
		Car();
		Car(const float * lla);
		Car(const Car & other);
		virtual ~Car();

		const Car & operator=(const Car & other);

		int getThrottle() const;
		void setThrottle(int throttle);

		void drive(int throttle);
		virtual void Move(const float * new_lla);

	private:
		virtual void serialize(std::ostream & os) const;

		int m_throttle;
};

#endif
