#include <iostream>

#include "NodeList.h"


std::ostream & operator<<(std::ostream & os, const NodeList & nodeList) {
	os << "[";
	for (size_t i = 0; i < nodeList.size(); ++i) {
		os << nodeList[i] << ", ";
	}
	if (!nodeList.empty()) os << "\b\b";
	os << "]";

	return os;
}


NodeList::NodeList() 
	: m_head(NULL) {}

NodeList::NodeList(size_t count, const DataType & value)
	: m_head(NULL)
{
	if (count) {
		m_head = new Node(value);
		Node * curr = m_head;
		for (size_t i = 1; i < count; ++i) {
			curr->m_next = new Node(value);
			curr = curr->m_next;
		}
	}
}

NodeList::NodeList(const NodeList & other) 
	: m_head(NULL)
{
	m_head = new Node(other.m_head->m_data);
	Node * curr = m_head, * otherCurr = other.m_head;
	for (; otherCurr->m_next != NULL; otherCurr = otherCurr->m_next, curr = curr->m_next) {
		curr->m_next = new Node(otherCurr->m_next->m_data);
	}
}

NodeList::~NodeList() {
	clear();
}


NodeList & NodeList::operator=(const NodeList & rhs) {
	clear();

	m_head = new Node(rhs.m_head->m_data);
	Node * curr = m_head, * rhsCurr = rhs.m_head;
	for (; rhsCurr->m_next != NULL; rhsCurr = rhsCurr->m_next, curr = curr->m_next) {
		curr->m_next = new Node(rhsCurr->m_next->m_data);
	}

	return *this;
}


Node * NodeList::front() {
	return m_head;
}

Node * NodeList::back() {
	if (empty()) return NULL; 

	Node * curr = m_head;
	for (; curr->m_next != NULL; curr = curr->m_next);

	return curr;
}

Node * NodeList::find(const DataType & target,
		Node * & previous,
		const Node * start)
{
	previous = NULL;
	if (empty()) return NULL;

	Node * curr = start ? const_cast<Node*>(start) : m_head;

	if (curr->m_data == target) return curr;

	for (; curr->m_next != NULL; curr = curr->m_next) {
		if (curr->m_next->m_data == target) {
			previous = curr;
			return curr->m_next;
		}
	}

	return NULL;
}

Node * NodeList::insertAfter(const DataType & target,
		const DataType & value) 
{
	Node * prev;
	Node * targetNode = find(target, prev);

	if (!targetNode) return NULL;

	Node * newNode = new Node(value);
	newNode->m_next = targetNode->m_next;
	targetNode->m_next = newNode;
	return newNode;
}

Node * NodeList::insertBefore(const DataType & target,
		const DataType & value) 
{
	Node * prev;
	Node * targetNode = find(target, prev);

	if (!targetNode) return NULL;

	if (!prev) {
		m_head = new Node(value);
		m_head->m_next = targetNode;
		return m_head;
	}

	prev->m_next = new Node(value);
	prev->m_next->m_next = targetNode;
	return prev->m_next;
}

Node * NodeList::erase(const DataType & target) {
	Node * prev;
	Node * targetNode = find(target, prev);

	if (!targetNode) return NULL;

	if (!prev) {
		m_head = m_head->m_next;
		return m_head;
	}

	prev->m_next = targetNode->m_next;
	delete targetNode;
	return prev->m_next;
}


DataType & NodeList::operator[](size_t position) {
	Node * curr = m_head;
	for (size_t i = 0; i < position; ++i) curr = curr->m_next;

	return curr->m_data;
}

const DataType & NodeList::operator[](size_t position) const {
	Node * curr = m_head;
	for (size_t i = 0; i < position; ++i) curr = curr->m_next;

	return curr->m_data;
}


size_t NodeList::size() const {
	size_t size = 0;
	for (Node * curr = m_head; curr != NULL; curr = curr->m_next) size++;
	return size;
}

bool NodeList::empty() const {
	return !m_head;
}

void NodeList::clear() {
	Node * deletePtr;
	for (Node * curr = m_head; curr != NULL; ) {
		deletePtr = curr;
		curr = curr->m_next;
		delete deletePtr;
	}
	m_head = NULL;
}
