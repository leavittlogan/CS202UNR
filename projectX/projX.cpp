//
// Name: projX.cpp
// Author: Logan Leavitt
// Purpose: Test Driver for the SmartPtr class
//
#include <iostream>
#include "SmartPtr.h"

int main() {
	std::cout << std::endl << "Testing SmartPtr Default ctor" << std::endl;
	SmartPtr sp1;	// Default-ctor
	sp1->setIntVal(1);
	sp1->setDoubleVal(0.25);
	std::cout << "Dereference Smart Pointer 1: " << *sp1 << std::endl;

	std::cout << std::endl << "Testing SmartPtr Copy ctor" << std::endl;
	SmartPtr sp2 = sp1;	// Copy-ctor
	sp2->setIntVal(2);
	sp2->setDoubleVal(0.5);
	std::cout << "Dereference Smart Pointer 1: " << *sp1 << std::endl;
	std::cout << "Dereference Smart Pointer 2: " << *sp2 << std::endl;

	std::cout << std::endl << "Testing SmartPtr Assignment operator" << std::endl;
	SmartPtr sp3;
	sp3 = sp1;	// Assignment operator
	sp3->setIntVal(4);
	sp3->setDoubleVal(0.0);
	std::cout << "Dereference Smart Pointer 1: " << *sp1 << std::endl;
	std::cout << "Dereference Smart Pointer 2: " << *sp2 << std::endl;
	std::cout << "Dereference Smart Pointer 3: " << *sp3 << std::endl;

	std::cout << std::endl << "Testing SmartPtr Parametrized ctor" << std::endl;
	DataType * test_ptr = new DataType;
	test_ptr->setIntVal(5);
	test_ptr->setDoubleVal(4.5);
	SmartPtr sp4(test_ptr);	// Parametrized-ctor
	std::cout << "Dereference Smart Pointer 1: " << *sp1 << std::endl;
	std::cout << "Dereference Smart Pointer 2: " << *sp2 << std::endl;
	std::cout << "Dereference Smart Pointer 3: " << *sp3 << std::endl;
	std::cout << "Dereference Smart Pointer 4: " << *sp4 << std::endl;

	std::cout << std::endl << "Testing SmartPtr Parametrized ctor with NULLdata" << std::endl;
	SmartPtr spNULL(NULL);	// Parametrized-ctor with NULL ptr
	
	std::cout << std::endl << "Testing SmartPtr Copy ctor with NULLdata SmartPtr" << std::endl;
	SmartPtr spNULL_cpy(spNULL);	// Copy-ctor with NULL ptr

	std::cout << std::endl << "Testing SmartPtr Assignment with NULLdata SmartPtr" << std::endl;
	SmartPtr spNULL_assign;
	spNULL_assign = spNULL;	// Assignment operator with NULL ptr

	std::cout << std::endl << "End-of-Scope, Destructors called in reverse order of SmartPtr creation" << std::endl
		<< "(spNull_assign, spNull_cpy, spNull, sp4, sp3, sp2, sp1): " << std::endl;

	// Destructors are called

	return 0;
}
