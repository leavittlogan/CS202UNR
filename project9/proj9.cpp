#include <iostream>
#include "ArrayQueue.h"
#include "NodeQueue.h"

template <class T>
void testQueue();

int main() {
	std::cout << std::endl << "\t/////////////////////" << std::endl
		<< "\t//Array Queue Tests//" << std::endl
		<< "\t/////////////////////" << std::endl;
	// Array Based Queue
	testQueue<ArrayQueue>();

	std::cout << std::endl << "\t////////////////////" << std::endl
		<< "\t//Node Queue Tests//" << std::endl
		<< "\t////////////////////" << std::endl;

	// Node Based Queue
	testQueue<NodeQueue>();

	return 0;
}

template <class T>
void testQueue() {
	DataType value1(1, 1);
	DataType value2(2, 2);
	DataType value3(3, 3);
	DataType value4(4, 4);
	DataType value5(5, 5);


	std::cout << std::endl << "\tTesting Constructors" << std::endl;

	T one;
	T two(5, value1);
	T three(two);

	std::cout << "1: " << one << std::endl;
	std::cout << "2: " << two << std::endl;
	std::cout << "3: " << three << std::endl;


	std::cout << std::endl << "\tTesting front(), back() and operator=" << std::endl;

	three.front() = value2;
	three.back() = value3;
	one = three;

	std::cout << "1: " << one << std::endl;
	std::cout << "2: " << two << std::endl;
	std::cout << "3: " << three << std::endl;


	std::cout << std::endl << "\tTesting push and pop" << std::endl;

	one.push(value4);
	one.pop();
	two.push(value4);
	two.push(value5);
	three.pop();
	three.pop();

	std::cout << "1: " << one << std::endl;
	std::cout << "2: " << two << std::endl;
	std::cout << "3: " << three << std::endl;


	std::cout << std::endl << "\tTesting clear, full, empty, and size" << std::endl;
	std::cout << "Clearing contents of List 1" << std::endl;
	one.clear();

	std::cout << std::boolalpha;
	std::cout << "1: " << one << std::endl
		<< "\tsize: " << one.size() << std::endl
		<< "\tempty: " << one.empty() << std::endl
		<< "\tfull: " << one.full() << std::endl;
	std::cout << "2: " << two << std::endl
		<< "\tsize: " << two.size() << std::endl
		<< "\tempty: " << two.empty() << std::endl
		<< "\tfull: " << two.full() << std::endl;
	std::cout << "3: " << three << std::endl
		<< "\tsize: " << three.size() << std::endl
		<< "\tempty: " << three.empty() << std::endl
		<< "\tfull: " << three.full() << std::endl;
}
