//
// Name: MyString.cpp
// Author: Logan K. Leavitt
// Purpose: Implement the MyString Class
//
#include <iostream>
#include <cstring>
#include "MyString.h"

//
// Constructors + Destructor
//

MyString::MyString() : m_buffer(NULL) {} //(1)

MyString::MyString(const char * str) : m_buffer(NULL) { //(2)
	buffer_allocate(strlen(str) + 1);
	strcpy(m_buffer, str);
}

MyString::MyString(const MyString & other_myStr) : m_buffer(NULL) { //(3)
	buffer_allocate(other_myStr.m_size);
	strcpy(m_buffer, other_myStr.m_buffer);
}

MyString::~MyString() { //(4)
	buffer_deallocate();
}

// returns size of m_buffer array, including '\n'
size_t MyString::size() const { //(5)
	return m_size;
}

// returns size of string, excluding '\n'
size_t MyString::length() const { //(6)
	return m_size - 1;
}

// returns point to c-string
const char * MyString::c_str() const { //(7)
	return m_buffer; 
}

//
// operator overloads
//

bool MyString::operator==(const MyString & other_myStr) const { //(8)
	return strcmp(m_buffer, other_myStr.m_buffer) == 0;
}

MyString & MyString::operator=(const MyString & other_myStr) { //(9)
	buffer_allocate(other_myStr.m_size);
	strcpy(m_buffer, other_myStr.m_buffer);

	return *this; 
}

MyString MyString::operator+(const MyString & other_myStr) const { //(10)
	char temp[m_size + other_myStr.m_size - 1];
	strcpy(temp, m_buffer);
	strcat(temp, other_myStr.m_buffer);

	return MyString(temp);
}

char & MyString::operator[](size_t index) { //(11a)
	return *(m_buffer + index);
}

const char & MyString::operator[](size_t index) const { //(11b)
	return *(m_buffer + index);
}

std::ostream & operator<<(std::ostream & os, const MyString & myStr) { //(12)
	os << myStr.m_buffer;
	return os; 
}

// frees memory pointed to by m_buffer
void MyString::buffer_deallocate() { //(13)
	delete [] m_buffer;
	m_buffer = NULL;
	m_size = 0;
}

// allocates (or reallocates) memory to m_buffer
void MyString::buffer_allocate(size_t size) { //(14)
	if (m_buffer) buffer_deallocate();

	try {
		m_buffer = new char [size];
		m_size = size;
	}
	catch(const std::bad_alloc & ex) {
		std::cout << "std::bad_alloc thrown in buffer_allocate" << std::endl;
	}
}
