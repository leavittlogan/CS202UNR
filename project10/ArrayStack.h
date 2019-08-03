#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#include <iostream>

template <class T> class ArrayStack;
template <class T> std::ostream & operator<<(std::ostream & os, const ArrayStack<T> & arrayStack);

const size_t MAX_STACKSIZE = 1000;

template <class T>
class ArrayStack {
	friend std::ostream & operator<< <> (std::ostream & os, const ArrayStack<T> & arrayStack);

	public:
		ArrayStack();
		ArrayStack(size_t count, const T & value);
		ArrayStack(const ArrayStack<T> & other);
		~ArrayStack();

		ArrayStack<T> & operator= (const ArrayStack & rhs);

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
		T m_container[MAX_STACKSIZE];
		size_t m_top;
};


template <class T>
ArrayStack<T>::ArrayStack() : m_top(0) {}

template <class T>
ArrayStack<T>::ArrayStack(size_t count, const T & value) :
	m_top(count)
{
	for (size_t i = 0; i < m_top; i++) {
		m_container[i] = value;
	}
}

template <class T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> & other) :
	m_top(other.m_top)
{
	for (size_t i = 0; i < m_top; i++) {
		m_container[i] = other.m_container[i];
	}
}

template <class T>
ArrayStack<T>::~ArrayStack() {}

template <class T>
ArrayStack<T> & ArrayStack<T>::operator= (const ArrayStack & rhs) {
	if (this != &rhs) {
		m_top = rhs.m_top;
		for (size_t i = 0; i < m_top; i++) {
			m_container[i] = rhs.m_container[i];
		}
	}

	return *this;
}


template <class T>
T & ArrayStack<T>::top() {
	return m_container[m_top - 1];
}

template <class T>
const T & ArrayStack<T>::top() const {
	return m_container[m_top - 1];
}


template <class T>
void ArrayStack<T>::push(const T & value) {
	if (!full()) {
		m_container[m_top++] = value;
	}
}

template <class T>
void ArrayStack<T>::pop() {
	if (!empty()) m_top--;
}


template <class T>
size_t ArrayStack<T>::size() const {
	return m_top;
}

template <class T>
bool ArrayStack<T>::empty() const {
	return !m_top;
}

template <class T>
bool ArrayStack<T>::full() const {
	return m_top == MAX_STACKSIZE;
}

template <class T>
void ArrayStack<T>::clear() {
	m_top = 0;
}


template <class T>
void ArrayStack<T>::serialize(std::ostream & os) const {
	os << "[";
	for (size_t i = m_top; i > 0; i--) {
		os << m_container[i - 1] << ", ";
	}
	if (!empty()) os << "\b\b";
	os << "]";
}

template <class T>
std::ostream & operator<<(std::ostream & os, const ArrayStack<T> & arrayStack) {
	arrayStack.serialize(os);
	return os;
}

#endif // ARRAYSTACK_H_
