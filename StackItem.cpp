#include <iostream>

#include "StackItem.hpp"

void StackItem::print() { 
	std::cout << "[" << static_cast<char>(typ+65) << ", " << val << ", " <<  &*next << "]" << std::endl;
}

