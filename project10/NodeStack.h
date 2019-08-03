#ifndef NODESTACK_H_
#define NODESTACK_H_

#include <iostream>

template <class T> class NodeStack;
template <class T> std::ostream & operator<<(std::ostream & os, const NodeStack<T> & nodeStack);

template <class T>
class Node {
	friend class NodeStack<T>;

	public:
		Node();
		Node(const T & data, Node<T> * next = NULL);

		T & data() { return m_data; }
		const T & data() const { return m_data; }

	private:
		Node<T> * m_next;
		T m_data;
};

template <class T>
Node<T>::Node() :
	m_next(NULL),
	m_data() {}

template <class T>
Node<T>::Node(const T & data, Node<T> * next) :
	m_next(next),
	m_data(data) {}


template <class T>
class NodeStack {
	friend std::ostream & operator<< <> (std::ostream & os, const NodeStack<T> & nodeStack);

	public:
		NodeStack();
		NodeStack(size_t count, const T & value);
		NodeStack(const NodeStack<T> & other);
		~NodeStack();

		NodeStack<T> & operator= (const NodeStack & rhs);

		T & top();
		const T & top() const;

		void push(const T & value);
		void pop();

		size_t size() const;
		bool empty() const;
		bool full() const;
		void clear();
		void serialize(std::ostream & os) const;

	private:
		Node<T> * m_top;
};

template <class T>
NodeStack<T>::NodeStack() : m_top(NULL) {}

template <class T>
NodeStack<T>::NodeStack(size_t count, const T & value) :
	m_top(NULL)
{
	if (count) {
		m_top = new Node<T>(value);
		Node<T> * curr = m_top;
		for (size_t i = 1; i < count; i++) {
			curr->m_next = new Node<T>(value);
			curr = curr->m_next;
		}
	}
}

template <class T>
NodeStack<T>::NodeStack(const NodeStack<T> & other) :
	m_top(NULL)
{
	if (other.m_top) {
		m_top = new Node<T>(other.m_top->m_data);
		Node<T> * curr = m_top;
		for (Node<T> * otherCurr = other.m_top->m_next; otherCurr != NULL; otherCurr  = otherCurr->m_next) {
			curr->m_next = new Node<T>(otherCurr->m_data);
			curr = curr->m_next;
		}
	}
}

template <class T>
NodeStack<T>::~NodeStack() {
	clear();
}


template <class T>
NodeStack<T> & NodeStack<T>::operator= (const NodeStack & rhs) {
	if (this != &rhs) {
		clear();

		if (rhs.m_top) {
			m_top = new Node<T>(rhs.m_top->m_data);
			Node<T> * curr = m_top;
			for (Node<T> * rhsCurr = rhs.m_top->m_next; rhsCurr != NULL; rhsCurr  = rhsCurr->m_next) {
				curr->m_next = new Node<T>(rhsCurr->m_data);
				curr = curr->m_next;
			}
		}
	}

	return *this;
}


template <class T>
T & NodeStack<T>::top() { return m_top->m_data; }

template <class T>
const T & NodeStack<T>::top() const { return m_top->m_data; }


template <class T>
void NodeStack<T>::push(const T & value) {
	m_top = new Node<T>(value, m_top);
}

template <class T>
void NodeStack<T>::pop() {
	if (!empty()) {
		Node<T> * delPtr = m_top;
		m_top = m_top->m_next;
		delete delPtr;
	}
}


template <class T>
size_t NodeStack<T>::size() const {
	size_t size = 0;
	for (Node<T> * curr = m_top; curr != NULL; curr = curr->m_next) size++;
	return size;
}

template <class T>
bool NodeStack<T>::empty() const {
	return !m_top;
}

template <class T>
bool NodeStack<T>::full() const {
	return false;
}

template <class T>
void NodeStack<T>::clear() {
	while (!empty()) pop();
}

template <class T>
void NodeStack<T>::serialize(std::ostream & os) const {
	os << "[";
	for (Node<T> * curr = m_top; curr != NULL; curr = curr->m_next) {
		os << curr->m_data << ", ";
	}
	if (!empty()) os << "\b\b";
	os << "]";
}

template <class T>
std::ostream & operator<< (std::ostream & os, const NodeStack<T> & nodeStack) {
	nodeStack.serialize(os);
	return os;
}

#endif
