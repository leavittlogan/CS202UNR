#include <iostream>

#include "ArrayList.h"

// amount to increment m_maxsize by when extra space is needed
const size_t SIZE_INCREMENT = 10;

std::ostream & operator<<(std::ostream & os, const ArrayList & arrayList) {
	os << "[";
	for (size_t i = 0; i < arrayList.m_size; i++) {
		os << arrayList.m_array[i] << ", ";
	}
	if (arrayList.m_size) os << "\b\b";
	os << "]";

	return os;
}



ArrayList::ArrayList() 
	: m_array(NULL)
	, m_size(0)
	, m_maxsize(0) {}



ArrayList::ArrayList(size_t count, const DataType & value) 
	: m_array(NULL)
	, m_size(0)
	, m_maxsize(0)
{
	resize(count);
	for (size_t i = 0; i < count; i++) m_array[i] = value;
	m_size = count;
}

ArrayList::ArrayList(const ArrayList & other) 
	: m_array(NULL)
	, m_size(0)
	, m_maxsize(0)
{
	resize(other.m_maxsize);
	for (size_t i = 0; i < other.m_size; i++) m_array[i] = other.m_array[i];
	m_size = other.m_size;
}

ArrayList::~ArrayList() {
	delete [] m_array;
}



ArrayList & ArrayList::operator=(const ArrayList & rhs) {
	resize(rhs.m_maxsize);
	for (size_t i = 0; i < rhs.m_size; i++) m_array[i] = rhs.m_array[i];
	m_size = rhs.m_size;

	return *this;
}



DataType * ArrayList::front() {
	if (m_size) {
		return m_array;
	} else {
		return NULL;
	}
}

DataType * ArrayList::back() {
	if (m_size) {
		return m_array + m_size - 1;
	} else {
		return NULL;
	}
}

DataType * ArrayList::find(const DataType & target,
			   DataType * & previous,
			   const DataType * start)
{
	previous = NULL;

	DataType * curr = start ? const_cast<DataType*>(start) : m_array;
	for (; curr < m_array + m_size; ++curr) {
		if (*curr == target) {
			if (curr != m_array) {
				previous = curr - 1;
			}
			return curr;
		}
	}

	return NULL;
}

DataType * ArrayList::insertAfter(const DataType & target, const DataType & value) {
	// expand array if no space
	if (m_maxsize == m_size) resize(m_maxsize + SIZE_INCREMENT);

	DataType * prev;
	DataType * arrayTarget = find(target, prev);

	if (!arrayTarget) return NULL; // failed to find target, return NULL

	DataType * curr = m_array + m_size;
	for (; curr != arrayTarget + 1; --curr) {
		*curr = *(curr - 1);
	}

	*curr = value;
	m_size++;
	return curr;
}

DataType * ArrayList::insertBefore(const DataType & target, const DataType & value) {
	// expand array if no space
	if (m_maxsize == m_size) resize(m_maxsize + SIZE_INCREMENT);

	DataType * prev;
	DataType * arrayTarget = find(target, prev);

	if (!arrayTarget) return NULL; // failed to find target, return NULL

	DataType * curr = m_array + m_size;
	for(; curr != arrayTarget; --curr) {
		*curr = *(curr - 1);
	}

	*curr = value;
	m_size++;
	return curr;
}

DataType * ArrayList::erase(const DataType & target) {
	DataType * prev;
	DataType * arrayTarget = find(target, prev);

	if (!arrayTarget) return NULL; // failed to find target, return NULL

	DataType * curr = arrayTarget;
	for (; curr != m_array + m_size - 1; curr++) {
		*curr = *(curr + 1);
	}

	m_size--;
	if (arrayTarget == m_array + m_size) return NULL;
	return arrayTarget;
}



DataType & ArrayList::operator[](size_t position) {
	return m_array[position];
}



size_t ArrayList::size() const {
	return m_size;
}

bool ArrayList::empty() const {
	return !m_size;
}

void ArrayList::clear() {
	m_size = 0;
}



void ArrayList::resize(size_t count) {
	if (count) {
		DataType * newArray = new DataType[count]; // maybe i should do an allocation check here to avoid segfaults

		for (size_t i = 0; i < m_size && i < count; i++) {
			newArray[i] = m_array[i];
		}

		delete [] m_array;
		m_array = newArray;
		m_maxsize = count;
		if (m_size > m_maxsize) m_size = m_maxsize;
	} else {
		delete [] m_array;
		m_array = NULL;
		m_maxsize = m_size = 0;
	}
}
