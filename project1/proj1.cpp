//
// Name: proj1.cpp
// Author: Logan Leavitt
// Purpose: Reads a given input file for a list of ten names,
// 	then sorts the list by length and then alphabetically,
// 	while printing the new sorted list to the terminal and output file
//
#include <iostream>
#include <fstream>

const int FILE_NAME_SIZE = 32;
const int NUM_ENTRIES = 10;
const int STR_LENGTH = 8;

// takes an array and the positions of two elements, then swaps them
void swap(int array[], int a, int b);

// prints names preceded by their original order to the desired output stream
void printNames(std::ostream &out, char names[][STR_LENGTH + 1], int nameOrder[], int numEntries);

// compares two elements either by length or alphabetically
// 	pass 'l' to compare by length
// 	pass 'a' to compare alphabetically
// returns -1 if string 1 should go first
// returns 0 if elements are equivalent for given sort type
// returns 1 if string 2 should go first
int compareElements(const char str1[], const char str2[], char sortType);

// sorts the list of names by swapping elements of the nameOrder array,
// sortType controls type of sort, pass 'l' for length and 'a' for alphabetically
// uses the bubble sort algorithm
void sort(char names[][STR_LENGTH + 1], int nameOrder[], int numEntries, char sortType);

// copies characters from source to destination until a NULL-character '\0' is found in source,
// then NULL-terminates destination too, and returns
void myStringCopy(char destination [], const char source []);

// counts characters in array str until a NULL-character '\0' is found,
// then it returns that number excluding '\0'
int myStringLength(const char str []);

// returns 0 when the strings match
// returns -1 if str1 comes first alphabetically 
// returns 1 if str2 comes first alphabetically 
int myStringCompare(const char str1 [], const char str2 []);

int main() {
	char inFileName[FILE_NAME_SIZE + 1], lengthFileName[FILE_NAME_SIZE + 1],
		alphaFileName[FILE_NAME_SIZE + 1];

	// open input file
	std::cout << "Enter name of input file: ";
	std::cin >> inFileName;

	std::ifstream inFile;
	inFile.open(inFileName);
	if (!inFile.is_open()) {
		std::cout << "Unable to open "
			<< inFileName 
			<< std::endl;
		return 1;
	}

	// open first output file
	std::cout << "Enter name of output file for names sorted by length: ";
	std::cin >> lengthFileName;

	std::ofstream lengthFile;
	lengthFile.open(lengthFileName);
	if (!lengthFile.is_open()) {
		std::cout << "Unable to open "
			<< lengthFileName
			<< std::endl;
		inFile.close();
		return 1;
	}

	// open second output file 
	std::cout << "Enter name of output file for names sorted alphabetically: ";
	std::cin >> alphaFileName;

	std::ofstream alphaFile;
	alphaFile.open(alphaFileName);
	if (!alphaFile.is_open()) {
		std::cout << "Unable to open "
			<< alphaFileName
			<<std::endl;
		inFile.close();
		lengthFile.close();
		return 1;
	}

	char names[NUM_ENTRIES][STR_LENGTH + 1];
	int nameOrder[NUM_ENTRIES];

	for (int i = 0; i < NUM_ENTRIES; i++) {
		inFile >> names[i];
		nameOrder[i] = i;
	}

	std::cout << std::endl;

	// print out unsorted names
	printNames(std::cout, names, nameOrder, NUM_ENTRIES);

	// sort list by length
	sort(names, nameOrder, NUM_ENTRIES, 'l');
	
	// print out sorted names to terminal and first output file
	printNames(std::cout, names, nameOrder, NUM_ENTRIES);
	printNames(lengthFile, names, nameOrder, NUM_ENTRIES);
	
	// sort list alphabetically
	sort(names, nameOrder, NUM_ENTRIES, 'a');
	
	// print out to terminal and second output file
	printNames(std::cout, names, nameOrder, NUM_ENTRIES);
	printNames(alphaFile, names, nameOrder, NUM_ENTRIES);

	inFile.close();
	lengthFile.close();
	alphaFile.close();

	return 0;
}

void swap(int array[], int a, int b) {
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void printNames(std::ostream &out, char names[][STR_LENGTH + 1], int nameOrder[], int numEntries) {
	for (int i = 0; i < numEntries; i++) {
		out << nameOrder[i] << " " << names[nameOrder[i]] << std::endl;
	}
	out << std::endl;
}


int compareElements(const char str1[], const char str2[], char sortType) {
	if (sortType == 'l') {
		if (myStringLength(str1) > myStringLength(str2)) {
			return 1;
		} else if (myStringLength(str2) > myStringLength(str1)) {
			return -1;
		} else {
			return 0;
		}
	} else if (sortType == 'a') {
		return myStringCompare(str1, str2); 
	} else {
		std::cout << "Invalid sort type passed to compareElements" << std::endl;
		return 0;
	}
}

void sort(char names[][STR_LENGTH + 1], int nameOrder[], int numEntries, char sortType) {
	bool swappedElementsFlag = true;
	for (int i = NUM_ENTRIES - 1; i > 1 && swappedElementsFlag; i--) {
		swappedElementsFlag = false;
		for (int j = 0; j < i; j ++) {
			if (compareElements(names[nameOrder[j]], names[nameOrder[j + 1]], sortType) == 1) {
				swappedElementsFlag = true;
				swap(nameOrder, j, j + 1);
			}
		}
	}
}

void myStringCopy(char destination [], const char source []) {
	int i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}

int myStringLength(const char str []) {
	int length = 0, i = 0;
	while (str[i++] != '\0') length++;

	return length;
}

int myStringCompare(const char str1 [], const char str2 []) {
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] < str2[i]) {
			return -1;
		} else if (str1[i] > str2[i]) {
			return 1;
		} else {
			i++;
		}
	}

	return 0;
}
