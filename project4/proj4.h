//
// Name: proj4.h
// Purpose: contains declarations of the required string functions
// 	and also constants found throughout the program
//
// note: definitions of these functions can be found in proj4.cpp
//
#ifndef PROJ4_H
#define PROJ4_H
#include <iostream>

const int MAX_STR_SIZE = 256;

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

#endif
