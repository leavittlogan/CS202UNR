//
// Name: RentalCar.h
// Purpose: contains the declaration of the
// 	RentalCar class
#ifndef RENTALCAR_H_
#define RENTALCAR_H_
#include "constants.h"
#include <iostream>

class RentalCar {
	public:
		RentalCar();
		RentalCar(int year, const char * make, const char * model, float price, bool available=false);

		void print(std::ostream & out) const ;
		float estimateCost(int days) const ;

		int getYear() const ;
		void getMake(char * cstring) const ;
		void getModel(char * cstring) const ;
		float getPrice() const ;
		bool getAvailable() const ;

		void setYear(int year);
		void setMake(const char * make);
		void setModel(const char * model);
		void setPrice(float price);
		void setAvailable(bool available);

	private:
		int m_year;
		char m_make[MAX_STR_SIZE];
		char m_model[MAX_STR_SIZE];
		float m_price;
		bool m_available;
};

#endif
