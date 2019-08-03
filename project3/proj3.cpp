//
// Name: proj3.cpp
// Author: Logan K. Leavitt
// Purpose: Work with classes and structs to allow the user
// 	to interact with multiple rental agencies
//
#include <iostream>
#include <fstream>
#include "proj3.h"
#include "RentalCar.h"
#include "RentalAgency.h"
#include "constants.h"

// prompts the user with a user menu
// returns their input
int userMenu();

// prompst user for input file and reads in data from that file
void getInput(RentalAgency * agencies, int size);

// takes a file to read from and the int array to write to
void readZipCode(std::ifstream & file, int * array);

// print out the cars for all agencies to the terminal
void printAgencies(RentalAgency * agencies, int size);

// takes an int array and prints out its zipcode
void printZipCode(int * zipcode);

// prompt the user for a car and the number of days
// prints out estimated cost to terminal
void estimateRentalCost(RentalAgency * agencies);

// finds single most expensive car and prints it to the terminal
void findMostExpensive(RentalAgency * agencies, int size);

// prints out the available cars from all agencies to an output file
void printAvailableCars(RentalAgency * agencies, int size);

int main() {
	RentalAgency agencies[NUM_AGENCIES];
	const char * warning = "Data must be read in before this option is available.";

	std::cout << "Welcome!" << std::endl;

	bool running = true, retrievedData = false;
	while (running) {
		switch (userMenu()) {
			case 1:
				getInput(agencies, NUM_AGENCIES);
				retrievedData = true;
				break;
			case 2:
				if (retrievedData)
					printAgencies(agencies, NUM_AGENCIES); 
				else
					std::cout << warning << std::endl;
				break;
			case 3:
				if (retrievedData)
					estimateRentalCost(agencies); 
				else
					std::cout << warning << std::endl;
				break;
			case 4:
				if (retrievedData)
					findMostExpensive(agencies, NUM_AGENCIES); 
				else
					std::cout << warning << std::endl;
				break;
			case 5:
				if (retrievedData)
					printAvailableCars(agencies, NUM_AGENCIES); 
				else
					std::cout << warning << std::endl;
				break;
			default:
				running = false;
				break;
		}
	}

	return 0;
}

// prompts the user with a user menu
// returns their input
int userMenu() {
	int command = 0;

	std::cout << std::endl << "\tMenu Options" << std::endl
		<< "1) Read in from file" << std::endl
		<< "2) Print car data to terminal" << std::endl
		<< "3) Estimate rental cost" << std::endl
		<< "4) Find most expensive car" << std::endl
		<< "5) Print available cars to seperate file" << std::endl
		<< "6) Exit" << std::endl;

	std::cout << "Enter an option number: ";
	
	std::cin >> command;

	while (command < 1 || command > 6) {
		std::cout << "Number must be from 1 to 6: ";
		std::cin >> command;
	}

	return command;
}

// prompst user for input file and reads in data from that file
void getInput(RentalAgency * agencies, int size) {
	char fileName[MAX_STR_SIZE];
	std::ifstream inFile;

	std::cout << "Enter the file name: ";
	std::cin >> fileName;

	inFile.open(fileName);
	if (!inFile.is_open()) {
		std::cout << "Unable to open " << fileName << std::endl;
		return;
	}

	for (int i = 0; i < size; i++, agencies++) {
		inFile >> agencies->name;	
		readZipCode(inFile, agencies->zipcode);

		RentalCar * carPtr = agencies->inventory;
		int year;
		char make[MAX_STR_SIZE], model[MAX_STR_SIZE];
		float price;
		bool available;
		for (int j = 0; j < NUM_CARS; j++, carPtr++) {
			inFile >> year >> make >> model >> price >> available;
			*carPtr = RentalCar(year, make, model, price, available);
		}
	}

	std::cout << "Successfully read file." << std::endl;
}

// takes a file to read from and the int array to write to
void readZipCode(std::ifstream & file, int * array) {
	char digit;
	
	for (int i = 0; i < 5; i++, array++) {
		file >> digit;
		*array = digit - '0';
	}
}

// print out the cars for all agencies to the terminal
void printAgencies(RentalAgency * agencies, int size) {
	for (int i = 0; i < size; i++, agencies++) {
		std::cout << agencies->name << " ";
		printZipCode(agencies->zipcode);
		std::cout << std::endl;

		RentalCar * carPtr = agencies->inventory;
		for (int j = 0; j < 5; j++, carPtr++) {
			carPtr->print(std::cout);
		}

		std::cout << std::endl;
	}
}

// takes an int array and prints out its zipcode
void printZipCode(int * zipcode) {
	for (int i = 0; i < 5; i++, zipcode++) {
		std::cout << *zipcode;
	}
}

// prompt the user for a car and the number of days
// prints out estimated cost to terminal
void estimateRentalCost(RentalAgency * agencies) {
	int agencyNum, carNum, days;

	std::cout << "Which agency are you interested in? (0-2): ";
	std::cin >> agencyNum;

	while (agencyNum < 0 || agencyNum >= NUM_AGENCIES) {
		std::cout << "Invalid number: ";
		std::cin >> agencyNum;
	}

	std::cout << "Which car are you interested in? (0-4): ";
	std::cin >> carNum;

	while (carNum < 0 || carNum >= NUM_CARS) {
		std::cout << "Invalid number: ";
		std::cin >> carNum;
	}

	std::cout << "How many days would you rent the car? ";
	std::cin >> days;

	RentalCar * carPtr = (agencies + agencyNum)->inventory + carNum;
	std::cout << "The cost would be approximately $" 
		<< carPtr->estimateCost(days) << std::endl;
}

// finds single most expensive car and prints it to the terminal
void findMostExpensive(RentalAgency * agencies, int size) {
	RentalCar * max = agencies->inventory;

	for (int i = 0; i < size; i++, agencies++) {
		RentalCar * carPtr = agencies->inventory;
		for (int j = 0; j < NUM_CARS; j++, carPtr++) {
			if (carPtr->getPrice() > max->getPrice()) {
				max = carPtr;
			}
		}
	}

	std::cout << "The most expensive car:" << std::endl;
	max->print(std::cout);
}

// prints out the available cars from all agencies to an output file
void printAvailableCars(RentalAgency * agencies, int size) {
	char fileName[MAX_STR_SIZE];
	std::ofstream outFile;

	std::cout << "Enter the name of the output file: ";
	std::cin >> fileName;

	outFile.open(fileName);

	if (!outFile.is_open()) {
		std::cout << "Unable to open " << fileName << std::endl;
		return;
	}

	for (int i = 0; i < size; i++, agencies++) {
		RentalCar * carPtr = agencies->inventory;
		for (int j = 0; j < NUM_CARS; j++, carPtr++) {
			if (carPtr->getAvailable()) {
				carPtr->print(outFile);
			}				
		}
	}

	std::cout << "Successfully wrote to " << fileName << std::endl;
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
