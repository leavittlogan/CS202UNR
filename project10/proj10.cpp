#include <iostream>
#include "ArrayStack.h"
#include "NodeStack.h"

template <template <typename> class T>
void testStack();

int main() {
	std::cout << std::endl << "\t///////////////////////" << std::endl
		<< "\t// Array Based Stack //" << std::endl
		<< "\t///////////////////////" << std::endl;
	testStack<ArrayStack>();

	std::cout << std::endl << "\t//////////////////////" << std::endl
		<< "\t// Node Based Stack //" << std::endl
		<< "\t//////////////////////" << std::endl;
	testStack<NodeStack>();

	return 0;
}

template <template <typename> class T>
void testStack() {

	std::cout << std::endl << "Testing stack with int type: " << std::endl;
	std::cout << std::endl << "\tTesting Constructors" << std::endl;

	T<int> one;
	T<int> two(4, 2);
	T<int> three(two);

	std::cout << "one: " << one << std::endl;
	std::cout << "two: " << two << std::endl;
	std::cout << "three: " << three << std::endl;


	std::cout << std::endl << "\tTesting operator=, top, and clear" << std::endl
		<< "( two.top() = 0; one = two; three.clear(); )" << std::endl;

	two.top() = 0;
	one = two;
	three.clear();

	std::cout << "one: " << one << std::endl;
	std::cout << "two: " << two << std::endl;
	std::cout << "three: " << three << std::endl;

	
	std::cout << std::endl << "\tTesting push and pop" << std::endl
		<< "( two.pop(); three.pop(); three.push(5); one.push(5); )" << std::endl;

	two.pop();
	three.pop();
	three.push(5);
	one.push(5);

	std::cout << one << std::endl;
	std::cout << two << std::endl;
	std::cout << three << std::endl;


	std::cout << std::endl << "\tTesting miscellanous methods" << std::endl
		<< "(clearing list 3)" << std::endl;
	three.clear();
	std::cout << "one: " << one << std::endl
		<< "\tsize: " << one.size() << std::endl
		<< "\tempty: " << std::boolalpha << one.empty() << std::endl
		<< "\tfull: " << one.full() << std::endl
		<< "two: " << two << std::endl
		<< "\tsize: " << two.size() << std::endl
		<< "\tempty: " << std::boolalpha << two.empty() << std::endl
		<< "\tfull: " << two.full() << std::endl
		<< "three: " << three << std::endl
		<< "\tsize: " << three.size() << std::endl
		<< "\tempty: " << std::boolalpha << three.empty() << std::endl
		<< "\tfull: " << three.full() << std::endl;


	std::cout << std::endl << "Testing stack with char type: " << std::endl;
	std::cout << std::endl << "\tTesting Constructors" << std::endl;

	T<char> oneC;
	T<char> twoC(4, 'b');
	T<char> threeC(twoC);

	std::cout << "one: " << oneC << std::endl;
	std::cout << "two: " << twoC << std::endl;
	std::cout << "three: " << threeC << std::endl;


	std::cout << std::endl << "\tTesting operator=, top, and clear" << std::endl
		<< "( two.top() = 'a'; one = two; three.clear(); )" << std::endl;

	twoC.top() = 'a';
	oneC = twoC;
	threeC.clear();

	std::cout << "one: " << oneC << std::endl;
	std::cout << "two: " << twoC << std::endl;
	std::cout << "three: " << threeC << std::endl;

	
	std::cout << std::endl << "\tTesting push and pop" << std::endl
		<< "( two.pop(); three.pop(); three.push('c'); one.push('c'); )" << std::endl;

	twoC.pop();
	threeC.pop();
	threeC.push('c');
	oneC.push('c');

	std::cout << "one: " << oneC << std::endl;
	std::cout << "two: " << twoC << std::endl;
	std::cout << "three: " << threeC << std::endl;


	std::cout << std::endl << "\tTesting miscellanous methods" << std::endl
		<< "(clearing list 3)" << std::endl;
	threeC.clear();
	std::cout << "one: " << oneC << std::endl
		<< "\tsize: " << oneC.size() << std::endl
		<< "\tempty: " << std::boolalpha << oneC.empty() << std::endl
		<< "\tfull: " << oneC.full() << std::endl
		<< "two: " << twoC << std::endl
		<< "\tsize: " << twoC.size() << std::endl
		<< "\tempty: " << std::boolalpha << twoC.empty() << std::endl
		<< "\tfull: " << twoC.full() << std::endl
		<< "three: " << threeC << std::endl
		<< "\tsize: " << threeC.size() << std::endl
		<< "\tempty: " << std::boolalpha << threeC.empty() << std::endl
		<< "\tfull: " << threeC.full() << std::endl;
}
