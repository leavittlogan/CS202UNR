//
// Name: SmartPtr.cpp
// Author: Logan Leavitt
// Purpose: Implementation of SmartPtr class
//
#include <iostream>
#include "SmartPtr.h"


SmartPtr::SmartPtr()
	: m_ptr(NULL)
	, m_refcount(NULL)
{
	m_ptr = new DataType();
	m_refcount = new size_t;
	*m_refcount = 1;

	std::cout << "SmartPtr Default Constructor for new allocation, Refcount="
		<< *m_refcount << std::endl;
}

SmartPtr::SmartPtr(DataType * data) 
	: m_ptr(data)
	, m_refcount(NULL)
{
	m_refcount = new size_t;
	*m_refcount = (m_ptr) ? 1 : 0;

	std::cout << "SmartPtr Parametrized Constructor from data pointer, RefCount="
		<< *m_refcount << std::endl;
}

SmartPtr::SmartPtr(const SmartPtr & other)
	: m_ptr(other.m_ptr)
	, m_refcount(other.m_refcount)
{
	if (m_ptr) {
		(*m_refcount)++;
	} else {
		m_refcount = new size_t;
		*m_refcount = 0;
	}

	std::cout << "SmartPtr Copy Constructor, RefCount=" << *m_refcount << std::endl;
}


SmartPtr::~SmartPtr() {
	if (*m_refcount) (*m_refcount)--;

	std::cout << "SmartPtr Destructor, RefCout=" << *m_refcount << std::endl;

	if (!*m_refcount) {
		delete m_ptr;
		delete m_refcount;
	}
}


SmartPtr & SmartPtr::operator=(const SmartPtr & rhs) {
	if (*m_refcount) (*m_refcount)--;
	if (!*m_refcount) {
		delete m_ptr;
		delete m_refcount;
		m_ptr = NULL;
		m_refcount = NULL;
	}

	m_ptr = rhs.m_ptr;
	if (m_ptr) {
		m_refcount = rhs.m_refcount;
		(*m_refcount)++;
	} else {
		m_refcount = new size_t;
		*m_refcount = 0;
	}

	std::cout << "SmartPtr Copy Assignment, RefCount=" << *m_refcount << std::endl;

	return *this;
}

DataType & SmartPtr::operator*() {
	return *m_ptr;
}

DataType * SmartPtr::operator->() {
	return m_ptr;
}
