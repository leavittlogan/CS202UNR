#include <iostream>
#include "NodeQueue.h"


std::ostream & operator<<(std::ostream & os, const NodeQueue & nodeQueue) {
	nodeQueue.serialize(os);
	return os;
}


NodeQueue::NodeQueue() :
	m_front(NULL),
	m_back(NULL)
{}

NodeQueue::NodeQueue(size_t size, const DataType & value) :
	m_front(NULL),
	m_back(NULL)
{
	if (size) {
		for (size_t i = 0; i < size; i++) push(value);
	}
}

NodeQueue::NodeQueue(const NodeQueue & other) :
	m_front(NULL),
	m_back(NULL)
{
	for (Node * curr = other.m_front; curr != NULL; curr = curr->m_next) {
		push(curr->m_data);
	}
}

NodeQueue::~NodeQueue() {
	Node * delPtr = NULL;
	for (Node * curr = m_front; curr != NULL; curr = curr->m_next) {
		delete delPtr;
		delPtr = curr;
	}
	delete delPtr;
}


NodeQueue & NodeQueue::operator=(const NodeQueue & rhs) {
	if (this != &rhs) {
		// deallocate any memory
		clear();

		// now allocate
		for (Node * curr = rhs.m_front; curr != NULL; curr = curr->m_next) {
			push(curr->m_data);
		}
	}

	return *this;
}


DataType & NodeQueue::front() {
	return m_front->m_data;
}

const DataType & NodeQueue::front() const {
	return m_front->m_data;
}


DataType & NodeQueue::back() {
	return m_back->m_data;
}

const DataType & NodeQueue::back() const {
	return m_back->m_data;
}


void NodeQueue::push(const DataType & value) {
	if (empty()) {
		m_front = m_back = new Node(value);
	} else {
		m_back->m_next = new Node(value);
		m_back = m_back->m_next;
	}
}

void NodeQueue::pop() {
	if (!empty()) {
		Node * temp = m_front;
		m_front = m_front->m_next;
		delete temp;
		
		if (!m_front) m_back = NULL;
	}
}


size_t NodeQueue::size() const {
	size_t count = 0;
	for (Node * curr = m_front; curr != NULL; curr = curr->m_next) {
		count++;
	}

	return count;
}

bool NodeQueue::empty() const {
	return !m_front;
}

bool NodeQueue::full() const {
	return false;
}

void NodeQueue::clear() {
	Node * delPtr = NULL;
	for (Node * curr = m_front; curr != NULL; curr = curr->m_next) {
		delete delPtr;
		delPtr = curr;
	}
	delete delPtr;
	m_front = m_back = NULL;
}

void NodeQueue::serialize(std::ostream & os) const {
	os << "[";
	for (Node * curr = m_front; curr != NULL; curr = curr->m_next) {
		os << curr->m_data << ", ";
	}
	if (!empty()) os << "\b\b";
	os << "]";
}
