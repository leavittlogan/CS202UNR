//
// Name: proj2.cpp
// Author: Logan Leavitt
// Purpose: Create a user menu which interacts
// 	with a list of RentalCar structs
//
#include <iostream>
#include <fstream>

const int STR_SIZE = 10;
const int NUM_CARS = 5;

struct RentalCar {
	int year;
	char make[STR_SIZE];
	char model[STR_SIZE];
	float price;
	bool available;
};

// modifies cars by swapping their values
void swapCars(RentalCar & car1, RentalCar & car2);

// sorts the list of cars by ascending price
void sortCars(RentalCar cars[]);

// prints menu prompt and gets input from user
// returns number the user entered
int userMenu();

// takes an array of RentalCars
// gets filename from user and retrieves data
void getCarData(RentalCar cars[], bool & retrievedData);

// prints the data for a single car in the required format to the terminal
void printCar(int j, const RentalCar & car);

// prints car data to the terminal
void printToTerminal(const RentalCar cars[]);

// prompts user for name of output file
// prints car data to output file
void printToFile(const RentalCar cars[]);

// asks user how many days they want to rent a car
// prints available cars, sorted by ascending price (without changing array))
void viewAvailableCars(const RentalCar cars[]);

// takes two ints by reference and swaps their value
void swapInts(int & x, int & y);

// asks the user which car they want rent
// if available, asks for number of days and then marks car as not available
void rentCar(RentalCar cars[]);

// returns number of characters in str, excluding '\0'
size_t myStringLength(const char * str);

// returns 0 when strings match
// returns -1 if first non-matching char is less in str1
// returns 1 if first non-matching char is less in str2
int myStringCompare(const char * str1, const char * str2);

// copies source string onto destination string
// returns pointer to destination string
char * myStringCopy(char * destination, const char * source);

// adds source string onto end of destination string
// returns pointer to destination string
char * myStringCat(char * destination, const char * source);

int main() {
	RentalCar cars[NUM_CARS];

	char warningMessage[] = "Data must be read in first.";

	std::cout << "Welcome to Rent-a-Car!" << std::endl;
	
	bool running = true, retrievedData = false;
	while (running) {
		switch (userMenu()) {
			case 1: 
				getCarData(cars, retrievedData);
				break;
			case 2:
				if (retrievedData) printToTerminal(cars);
				else std::cout << warningMessage << std::endl;
				break;
			case 3:
				if (retrievedData) printToFile(cars);
				else std::cout << warningMessage << std::endl;
				break;
			case 4:
				if (retrievedData) sortCars(cars);
				else std::cout << warningMessage << std::endl;
				break;
			case 5:
				if (retrievedData) viewAvailableCars(cars);
				else std::cout << warningMessage << std::endl;
				break;
			case 6:
				if (retrievedData) rentCar(cars);
				else std::cout << warningMessage << std::endl;
				break;
			default:
				running = false;
				break;
		}
	}
	return 0;
}

// modifies cars by swapping their values
void swapCars(RentalCar & car1, RentalCar & car2) {
	RentalCar temp = car1;
	car1 = car2;
	car2 = temp;
}

// sorts the list of car by ascending price
void sortCars(RentalCar cars[]) {
	for (int i = NUM_CARS - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (cars[j].price > cars[j + 1].price) {
				swapCars(cars[j], cars[j + 1]);
			}
		}
	}
	std::cout << "Array successfully sorted" << std::endl;
}

// prints menu prompt and gets input from user
// returns number the user entered
int userMenu() {
	int command = 0;

	std::cout << std::endl << "\tMenu Options" << std::endl
		<< "1) Read in car data" << std::endl
		<< "2) Print car data to terminal" << std::endl
		<< "3) Print car data to output file" << std::endl
		<< "4) Sort cars by price" << std::endl
		<< "5) Show available cars and calculate price" << std::endl
		<< "6) Rent a car" << std::endl
		<< "7) Exit" << std::endl;

	std::cout << "Enter an option number: ";
	
	std::cin >> command;

	while (command < 1 || command > 7) {
		std::cout << "Number must be from 1 to 7: ";
		std::cin >> command;
	}

	return command;
}

// takes an array of RentalCars
// gets filename from user and retrieves data
void getCarData(RentalCar cars[], bool & retrievedData) {
	char fileName[32];
	std::ifstream inputFile;

	std::cout << "Enter filename to retrieve data from: ";
	std::cin >> fileName;

	inputFile.open(fileName);
	if (inputFile.is_open()) {
		for (int i = 0; i < NUM_CARS; i++) {
			inputFile >> cars[i].year
				>> cars[i].make
				>> cars[i].model
				>> cars[i].price
				>> cars[i].available;
		}
		std::cout << "Successfully opened " << fileName << std::endl;
		retrievedData = true;
	} else {
		std::cout << "Unable to open " << fileName << std::endl;
	}
}

// prints the data for a single car in the required format to the terminal
void printCar(int j, const RentalCar & car) {
		std::cout << "[" << j << "]: "
			<< car.year << " "
			<< car.make << " "
			<< car.model << ", $"
			<< car.price << " per day, Available: "
			<< std::boolalpha << car.available
			<< std::endl;
}

// prints car data to the terminal
void printToTerminal(const RentalCar cars[]) {
	for (int i = 0; i < NUM_CARS; i++) {
		printCar(i, cars[i]);
	}
}

// prompts user for name of output file
// prints car data to output file
void printToFile(const RentalCar cars[]) {
	char fileName[32];
	std::ofstream outputFile;

	std::cout << "Enter filename to print data to: ";
	std::cin >> fileName;

	outputFile.open(fileName);
	if (outputFile.is_open()) {
		for (int i = 0; i < NUM_CARS; i++) {
			outputFile << cars[i].year << " "
				<< cars[i].make << " "
				<< cars[i].model << " "
				<< cars[i].price << " "
				<< cars[i].available << std::endl;
		}
		std::cout << "Successfully wrote to " << fileName << std::endl;
	} else {
		std::cout << "Unable to open " << fileName << std::endl;
	}
}

// asks user how many days they want to rent a car
// prints available cars, sorted by ascending price (without changing array))
void viewAvailableCars(const RentalCar cars[]) {
	int days;

	std::cout << "How many days do you want to rent a car for? " << std::endl;
	std::cin >> days;

	int carOrder[NUM_CARS];
	for (int i = 0; i < NUM_CARS; i++) {
		carOrder[i] = i;
	}

	// sorts cars without affecting array by swapping int values in carOrder array
	for (int i = NUM_CARS - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (cars[carOrder[j]].price > cars[carOrder[j + 1]].price) {
				swapInts(carOrder[j], carOrder[j + 1]);
			}
		}
	}

	for (int i = 0; i < NUM_CARS; i++) {
		if (cars[carOrder[i]].available) {
			std::cout << "[" << carOrder[i] << "]: "
				<< cars[carOrder[i]].year << " "
				<< cars[carOrder[i]].make << " "
				<< cars[carOrder[i]].model 
				<< ", Total Cost: $" 
				<< cars[carOrder[i]].price * days
				<< std::endl;
		}
	}
}

// takes two ints by reference and swaps their value
void swapInts(int & x, int & y) {
	int temp = x;
	x = y;
	y = temp;
}

// asks the user which car they want rent
// if available, asks for number of days and then marks car as not available
void rentCar(RentalCar cars[]) {
	int i;

	std::cout << "Which car would you like to rent? Enter index of car: ";
	std::cin >> i;

	while (i < 0 || i >= NUM_CARS) {
		std::cout << "Index must be from 0 and "
			<< NUM_CARS - 1 << ": ";
		std::cin >> i;
	}

	if (cars[i].available) {
		int days;

		std::cout << "How many days would you like to rent the "
			<< cars[i].make << " " << cars[i].model << ": ";

		std::cin >> days;

		cars[i].available = false;

		std::cout << "The " << cars[i].make << " " << cars[i].model 
			<< " has been rented for $" << days * cars[i].price << std::endl;
	} else {
		std::cout << "This car is not available to rent" << std::endl;
	}
}

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
