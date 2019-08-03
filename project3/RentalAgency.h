//
// Name: RentalAgency.h
// Purpose: contains the declaration of the
// 	RentalAgency struct
//
#ifndef RENTALAGENCY_H
#define RENTALAGENCY_H
#include "RentalCar.h"
#include "constants.h"

struct RentalAgency {
	char name[MAX_STR_SIZE];
	int zipcode[5];
	RentalCar inventory[NUM_CARS];
};

#endif
