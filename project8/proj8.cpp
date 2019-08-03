#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"

int main(){
	DataType value1(1, 1);
	DataType value2(2, 2);
	DataType value3(3, 3);
	DataType value4(4, 4);
	DataType value5(5, 5);


	std::cout << std::endl << "\t////////////////////" << std::endl
		<< "\t//Array Based List//" << std::endl
		<< "\t////////////////////" << std::endl;


	std::cout << std::endl << "\tTesting Default, Parameterized, and Copy Ctor" << std::endl;
	// Default Constructor
	ArrayList list1;

	// Parameterized Constructor
	ArrayList list2(3, value1);

	// Copy Constructor
	ArrayList list3(list2);
	
	std::cout << "List 1: " << list1 << std::endl
		<< "List 2: " << list2 << std::endl
		<< "List 3: " << list3 << std::endl;


	std::cout << std::endl << "\tTesting = operator" << std::endl;
	list1 = list2;
	std::cout << "List 1: " << list1 << std::endl
		<< "List 2: " << list2 << std::endl
		<< "List 3: " << list3 << std::endl;


	std::cout << std::endl << "\tTesting [] operator" << std::endl;
	list1[1] = value2;
	list1[2] = value3;
	std::cout << "List 1: " << list1 << std::endl;

	
	std::cout << std::endl << "\tTesting front (6), back (7), and find (8)" << std::endl
		<< "List 1: " << list1 << std::endl
		<< "front: " << *list1.front() << std::endl
		<< "back: " << *list1.back() << std::endl;
	DataType * prev;
	std::cout << "find {2, 2}: " << *list1.find(value2, prev) << std::endl
		<< "And previous ptr after calling find: " << *prev << std::endl;


	std::cout << std::endl << "\tTesting insertAfter and insertBefore" << std::endl
		<< "(Inserting {4, 4} before {1, 1} and after {3, 3}, then inserting" << std::endl
		<< "{5, 5} before and after {2, 2})" << std::endl;
	list1.insertBefore(value1, value4);
	list1.insertAfter(value3, value4);
	list1.insertBefore(value2, value5);
	list1.insertAfter(value2, value5);
	std::cout << "List 1: " << list1 << std::endl;


	std::cout << std::endl << "\tTesting erase (erasing {3, 3})" << std::endl;
	list1.erase(value3);
	std::cout << "List 1: " << list1 << std::endl;


	std::cout << std::endl << "\tTesting extra functionality of find" << std::endl
		<< "First find call: " << *list1.find(value5, prev) << std::endl
		<< "and corresponding prev ptr: " << *prev << std::endl
		<< "Second find call: " << *list1.find(value5, prev, list1.find(value5, prev) + 1) << std::endl
		<< "and corresponding prev ptr: " << *prev << std::endl;


	std::cout << std::endl << "\tTesting size (15), empty (16), and clear (17)" << std::endl
		<< "(clearing contents of list 2)" << std::endl;
	list2.clear();
	std::cout << std::boolalpha
		<< "List 1:" << list1 << std::endl
		<< "\tsize(): " << list1.size() << std::endl
		<< "\tempty(): " << list1.empty() << std::endl
		<< "List 2:" << list2 << std::endl
		<< "\tsize(): " << list2.size() << std::endl
		<< "\tempty(): " << list2.empty() << std::endl
		<< "List 3:" << list3 << std::endl
		<< "\tsize(): " << list3.size() << std::endl
		<< "\tempty(): " << list3.empty() << std::endl;



	std::cout << std::endl << "\t///////////////////" << std::endl
		<< "\t//Node Based List//" << std::endl
		<< "\t///////////////////" << std::endl;

	std::cout << std::endl << "\tTesting Default, Parameterized, and Copy Ctor" << std::endl;
	// Default Constructor
	NodeList nodeList1;

	// Parameterized Constructor
	NodeList nodeList2(3, value1);

	// Copy Constructor
	NodeList nodeList3(nodeList2);
	
	std::cout << "List 1: " << nodeList1 << std::endl
		<< "List 2: " << nodeList2 << std::endl
		<< "List 3: " << nodeList3 << std::endl;


	std::cout << std::endl << "\tTesting = operator" << std::endl;
	nodeList1 = nodeList2;
	std::cout << "List 1: " << nodeList1 << std::endl
		<< "List 2: " << nodeList2 << std::endl
		<< "List 3: " << nodeList3 << std::endl;


	std::cout << std::endl << "\tTesting [] operator" << std::endl;
	nodeList1[1] = value2;
	nodeList1[2] = value3;
	std::cout << "List 1: " << nodeList1 << std::endl;


	std::cout << std::endl << "\tTesting front (6), back (7), and find (8)" << std::endl
		<< "List 1: " << nodeList1 << std::endl
		<< "front: " << nodeList1.front()->data() << std::endl
		<< "back: " << nodeList1.back()->data() << std::endl;
	Node * prevNode;
	std::cout << "find {2, 2}: " << nodeList1.find(value2, prevNode)->data() << std::endl
		<< "And previous ptr after calling find: " << prevNode->data() << std::endl;


	std::cout << std::endl << "\tTesting insertAfter and insertBefore" << std::endl
		<< "(Inserting {4, 4} before {1, 1} and after {3, 3}, then inserting" << std::endl
		<< "{5, 5} before and after {2, 2})" << std::endl;
	nodeList1.insertBefore(value1, value4);
	nodeList1.insertAfter(value3, value4);
	nodeList1.insertBefore(value2, value5);
	nodeList1.insertAfter(value2, value5);
	std::cout << "List 1: " << nodeList1 << std::endl;


	std::cout << std::endl << "\tTesting erase (erasing {3, 3})" << std::endl;
	nodeList1.erase(value3);
	std::cout << "List 1: " << nodeList1 << std::endl;


	std::cout << std::endl << "\tTesting size (15), empty (16), and clear (17)" << std::endl
		<< "(clearing contents of list 2)" << std::endl;
	nodeList2.clear();
	std::cout << std::boolalpha
		<< "List 1:" << nodeList1 << std::endl
		<< "\tsize(): " << nodeList1.size() << std::endl
		<< "\tempty(): " << nodeList1.empty() << std::endl
		<< "List 2:" << nodeList2 << std::endl
		<< "\tsize(): " << nodeList2.size() << std::endl
		<< "\tempty(): " << nodeList2.empty() << std::endl
		<< "List 3:" << nodeList3 << std::endl
		<< "\tsize(): " << nodeList3.size() << std::endl
		<< "\tempty(): " << nodeList3.empty() << std::endl;

	return 0;
}
