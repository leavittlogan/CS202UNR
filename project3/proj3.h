//
// Name: proj3.h
// Purpose: contains declarations of the required string functions
//
// note: definitions of these functions can be found in proj3.cpp
//
#ifndef PROJ3_H
#define PROJ3_H

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
