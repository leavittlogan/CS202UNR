//
// Name: Vehicle.h
// Author: Logan K. Leavitt
// Purpose: Declaration of Vehicle Class
//
#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>

class Vehicle {
	public:
		Vehicle();
		Vehicle(const float * lla);
		Vehicle(const Vehicle & other);
		virtual ~Vehicle();

		const Vehicle & operator=(const Vehicle & other);
		friend std::ostream & operator<<(std::ostream & os, const Vehicle & v);

		const float * GetLLA() const;
		void SetLLA(const float * lla);

		virtual void Move(const float * new_lla) = 0;

	protected:
		float m_lla[3];

	private:
		virtual void serialize(std::ostream & os) const;
};

#endif
