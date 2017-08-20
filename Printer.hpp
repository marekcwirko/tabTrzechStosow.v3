#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <iostream>

#include "MultiStack.hpp"
#include "StackItem.hpp"

class Printer {
public:	
	static void print(StackItem *item) {
		std::cout << "[" 
		<< static_cast<char>(item->getType()+65) << ", " 
		<< item->getValue() << ", " 
		<< item->getIdx() << ", " 
		<< item->getNextIdx()  
		<< "]" << std::endl; 
	}
};

#endif
