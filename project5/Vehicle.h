//
// Name: Vehicle.h
// Author: Logan K. Leavitt
// Purpose: declaration of Vehicle base class
//
#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <iostream>

const int LAT = 0;
const int LON = 1;
const int ALT = 2;

class Vehicle {
	public:
		// Constructors/Destructor
		Vehicle();
		Vehicle(int vin, float * lla);
		Vehicle(const Vehicle & v);
		~Vehicle();

		// Operator overloads
		const Vehicle & operator=(const Vehicle & rhs);
		friend std::ostream & operator<<(std::ostream & os, const Vehicle & v);

		// getters and setters
		const float * getLLA() const;
		int getVIN() const;
		void setLLA(const float * lla);

		void move(float * lla) const;

		// getter for static member s_idgen
		static int getIdgen();

	protected:
		float m_lla[3];
		const int m_vin;

	private:
		static int s_idgen;
};

#endif
