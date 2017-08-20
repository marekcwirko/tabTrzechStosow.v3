#ifndef MULTISTACK_HPP
#define MULTISTACK_HPP

#include "StackItem.hpp"

enum Resizing {
	DOWN = -1, UP = 1
};

class MultiStack {	

public:
	MultiStack(StackItem *tab, int tabSize, StackItem **stos, int stosSize, int stosCnt) 
		: tab(tab), tabSize(tabSize), stos(stos), stosSize(stosSize), stosCnt(stosCnt) { };
	StackItem* newStackItem(StackType typ, long value);
	bool push(StackItem *item);
	StackItem pop(StackType typ);
	void clear(StackType typ);
	void clear();
	void print();
	char printType(StackType typ) { return static_cast<char>(typ+65); } 
	void printError();

private:
	void clearingOneStack(StackItem *itm);
	
private:
	StackItem *tab;
	const int tabSize;
	StackItem **stos;	
	int stosSize;
	const int stosCnt;	
};

#endif
