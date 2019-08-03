#include <iostream>
#include "ArrayQueue.h"


std::ostream & operator<<(std::ostream & os, const ArrayQueue & arrayQueue) {
	arrayQueue.serialize(os);
	return os;
}


ArrayQueue::ArrayQueue() :
	m_front(0),
	m_back(ARRAY_MAX - 1),
	m_size(0) 
{}

ArrayQueue::ArrayQueue(size_t count, const DataType & value) :
	m_front(0)
{
	m_size = count > ARRAY_MAX ? ARRAY_MAX : count;
	m_back = m_size ? m_size - 1 : ARRAY_MAX - 1;

	for (size_t i = 0; i < m_size; i++) {
		m_array[i] = value;
	}
}


ArrayQueue::ArrayQueue(const ArrayQueue & other) :
	m_front(other.m_front),
	m_back(other.m_back),
	m_size(other.m_size)
{
	for (size_t i = 0; i < m_size; i++) {
		m_array[(m_front + i) % ARRAY_MAX] = other.m_array[(m_front + i) % ARRAY_MAX];
	}
}

ArrayQueue::~ArrayQueue() {}


ArrayQueue & ArrayQueue::operator=(const ArrayQueue & rhs) {
	if (this != &rhs) {
		m_front = rhs.m_front;
		m_back = rhs.m_back;
		m_size = rhs.m_size;
		for (size_t i = 0; i < m_size; i++) {
			m_array[(m_front + i) % ARRAY_MAX] = rhs.m_array[(m_front + i) % ARRAY_MAX];
		}
	}

	return *this;
}


DataType & ArrayQueue::front() {
	return m_array[m_front];
}

const DataType & ArrayQueue::front() const {
	return m_array[m_front];
}


DataType & ArrayQueue::back() {
	return m_array[m_back];
}

const DataType & ArrayQueue::back() const {
	return m_array[m_back];
}


void ArrayQueue::push(const DataType value) {
	if (!full()) {
		m_back = (m_back + 1) % ARRAY_MAX;
		m_array[m_back] = value;
		m_size++;
	}
}

void ArrayQueue::pop() {
	if (!empty()) {
		m_front = (m_front + 1) % ARRAY_MAX;
		m_size--;
	}
}


size_t ArrayQueue::size() const {
	return m_size;
}

bool ArrayQueue::empty() const {
	return m_size == 0;
}

bool ArrayQueue::full() const {
	return m_size == ARRAY_MAX;
}

void ArrayQueue::clear() {
	m_size = 0;
	m_front = (m_back + 1) % ARRAY_MAX;
}

void ArrayQueue::serialize(std::ostream & os) const {
	os << "[";
	for (size_t i = 0; i < m_size; i++) {
		os << m_array[(m_front + i) % ARRAY_MAX] << ", ";
	}
	if (!empty()) os << "\b\b";
	os << "]";
}
