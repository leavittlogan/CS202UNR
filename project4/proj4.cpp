//
// Name: proj4.cpp
// Author: Logan K. Leavitt
// Purpose: expand on the rental agency concept with several classes
//
#include <iostream>
#include <fstream>
#include "proj4.h"
#include "Sensor.h"
#include "Car.h"
#include "Agency.h"

// prints the user menu and prompts for an option #
int userMenu();

// prompts user for input file and reads in data
void readData(Agency & agency, bool & retrievedData);

// prints # of sensors by type and in total
void printSensors();

// finds the most expensive, available car and asks user
// if they want to rent it
void findMostExpensive(Agency & agency);

int main () {
	Agency agency;
	std::cout << "Welcome to Rent-a-Car!" << std::endl;

	bool running = true, retrievedData = false;
	char warning[] = "Must read in data first...";
	while (running) {
		switch (userMenu()) {
			case 1:
				readData(agency, retrievedData);
				break;
			case 2:
				if (retrievedData) agency.printAllData();
				else std::cout << warning << std::endl;
				break;
			case 3:
				if (retrievedData) printSensors();
				else std::cout << warning << std::endl;
				break;
			case 4:
				if (retrievedData) findMostExpensive(agency);
				else std::cout << warning << std::endl;
				break;
			default:
				running = false;
				break;
		}
	}

	return 0;
}

// prints the user menu and prompts for an option #
int userMenu() {
	int option;

	std::cout << std::endl << "\tMenu:" << std::endl
		<< "1) Read in data (must be done first)" << std::endl
		<< "2) Print out cars" << std::endl
		<< "3) Print total number of sensors" << std::endl
		<< "4) Find most expensive available car" << std::endl
		<< "5) Exit" << std::endl
		<< "Enter option number: ";
	
	std::cin >> option;
	while (option <= 0 || option > 5) {
		std::cout << "Please enter valid number: ";
		std::cin >> option;
	}

	return option;
}

// prompts user for input file and reads in data
void readData(Agency & agency, bool & retrievedData) {
	std::ifstream file;
	char fileName[MAX_STR_SIZE];

	std::cout << "Please enter name of file: ";
	std::cin >> fileName;

	file.open(fileName);
	if (!file.is_open()) {
		std::cout << "Unable to open " << fileName << std::endl;
		return;
	}

	agency.readAllData(file);

	std::cout << "File successfully read!" << std::endl;
	retrievedData = true;
}

// prints # of sensors by type and in total
void printSensors() {
	std::cout << std::endl
		<< "Total GPS sensors: " << Sensor::getGpsCnt() << std::endl
		<< "Total Camera sensors: " << Sensor::getCameraCnt() << std::endl
		<< "Total Lidar sensors: " << Sensor::getLidarCnt() << std::endl
		<< "Total Radar sensors: " << Sensor::getRadarCnt() << std::endl
		<< "Total sensors: " << Sensor::getGpsCnt() + Sensor::getCameraCnt()
					+ Sensor::getLidarCnt() + Sensor::getRadarCnt()
		<< std::endl;
}

// finds the most expensive, available car and asks user
// if they want to rent it
void findMostExpensive(Agency & agency) {
	Car * max = nullptr;
	int i;

	std::cout << std::endl;

	// find first available car
	for (i = 0; i < NUM_CARS; i++) {
		if (agency[i].getAvailable()) {
			max = &agency[i];
			break;
		}
	}

	if (max == nullptr) {
		std::cout << "No available cars" << std::endl;
		return;
	}

	for (i = i + 1; i < NUM_CARS; i++) {
		if (agency[i].getAvailable() && agency[i].getFinalPrice() > max->getFinalPrice()) {
			max = &agency[i];
		}
	}

	std::cout << "The most expensive car:" << std::endl;
	max->print();

	char answer;
	std::cout << "Would you like to rent it? (y/n): ";
	std::cin >> answer;

	if (answer == 'y') {
		char name[MAX_STR_SIZE];

		std::cout << "Great! Enter your first name: ";
		std::cin >> name;

		*max + name;

		std::cout << "Car successfully rented!" << std::endl;
	} else {
		std::cout << "That's too bad..." << std::endl;
	}
}

//
// string function definitions
//

// returns number of characters in str, excluding '\0'
size_t myStringLength(const char * str) {
	size_t length = 0;
	while (*(str++)) length++;
	return length;
}

// returns 0 when strings match
// returns -1 if first non-matching char is less in str1
// returns 1 if first non-matching char is less in str2
int myStringCompare(const char * str1, const char * str2) {
	while (*str1 || *str2) {
		if (*str1 != *str2) {
			if (*str1 < *str2) {
				return -1;
			} else {
				return 1;
			}
		}
		str1++;
		str2++;
	}
	return 0;
}

// copies source string onto destination string
// returns pointer to destination string
char * myStringCopy(char * destination, const char * source) {
	char * dest_ptr = destination;
	while (*source) {
		*(dest_ptr++) = *(source++);
	}
	*dest_ptr = '\0';

	return destination;
}

// adds source string onto end of destination string
// returns pointer to destination string
char * myStringCat(char * destination, const char * source) {
	char * dest_ptr = destination;
	while (*dest_ptr) dest_ptr++;

	myStringCopy(dest_ptr, source);

	return destination;
}
