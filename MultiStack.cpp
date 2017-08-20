#include <iostream>

#include "MultiStack.hpp"
#include "StackItem.hpp"
#include "Printer.hpp"

StackItem* MultiStack::newStackItem(StackType typ, long value) {
	StackItem item;
	for(int i =0; i<tabSize; i++) {
		if(tab[i].getType() == NA) {
			tab[i] = StackItem(typ, value, i);	
			return &tab[i];
		}
	}
	return 0;
}

bool MultiStack::push(StackItem *item) {
	if(item) {
		if(stosSize == tabSize) {
			return false;
		}
		stosSize++;
		StackType typ = item->getType();
		if (stos[typ]) {
			item->setNext(stos[typ], stos[typ]->getIdx());
			stos[typ] = item;
		} else {
			stos[typ] = item;
		}
		
		std::cout << "<< ";
		Printer::print(item);
		return true;
	}
	return false;
}

StackItem MultiStack::pop(StackType typ) {
	StackItem popped;
	if(typ != NA) {
		if (stos[typ]) {
			popped = *stos[typ];
			if(popped.getType() != NA) {
				stosSize--;
				//stos[typ]->clear();
				stos[typ] = stos[typ]->getNext();
				std::cout << ">> ";
				Printer::print(&popped);			
			}
		}		
	} 
	return popped;
}

void MultiStack::clear(StackType typ) {
	std::cout << "clearing items of type: " << static_cast<char>(typ+65) << std::endl;
	clearingOneStack(stos[typ]);
}

void MultiStack::clearingOneStack(StackItem *itm) {
	if(itm) {
		clearingOneStack(itm->getNext());
		//deleteItm(item);
		itm->clear();
	}
}

void MultiStack::clear() {
	// may be any iteration
	clear(A);
	clear(B);
	clear(C); 
}

void MultiStack::print() {
	std::cout << "TOTAL TABLE: " << std::endl;
	if(tab) {
		for(int i =0; i<tabSize; i++) {
			if(tab[i].getType() != NA) {
				Printer::print(&tab[i]);
			} else {
				std::cout << "[]" << std::endl;
			}
		}
	}
	std::cout << "---" << std::endl;
}

void MultiStack::printError() {
	std::cout << "FULL UP TO LIMIT... wait till be something popped." << std::endl;
}

