#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <time.h> 

#include "MultiStack.hpp"
#include "StackItem.hpp" 

#define ATTEMPTS_CNT 17
#define TAB_SIZE 13

int sleep(unsigned long milisec)   
{   
    struct timespec req={0};   
    time_t sec=(int)(milisec/1000);   
    milisec=milisec-(sec*1000);   
    req.tv_sec=sec;   
    req.tv_nsec=milisec*1000000L;   
    while(nanosleep(&req,&req)==-1)   
        continue;   
    return 1;   
} 

int main(int argc, char** argv) {
	
	// table constrained by unexpandable TAB_SIZE_MAX == hard limit, 
	// then refuse to get new one in
	StackItem tab[TAB_SIZE];
	// handlers	
	StackItem **stosABC = new StackItem*[STACK_CNT];
	// where they are
	stosABC[A] = 0;
	stosABC[B] = 0;
	stosABC[C] = 0;
	
	int stosSize  = 0;
	MultiStack *scheduler = new MultiStack(tab, TAB_SIZE, stosABC, stosSize, STACK_CNT);
	StackType typ;
	StackItem item;
	bool ok;
	long value;
	for(int i=0; i<ATTEMPTS_CNT ; i++) {
		srand(time(NULL));
		sleep(1000);
		// push one
		typ = static_cast<StackType> ((rand() % STACK_CNT)); // 0 -2
		value = (rand() % LONG_MAX);
		StackItem *item = scheduler->newStackItem(typ, value);
		ok = scheduler->push(item);
		if(!ok) {
			// ignore
			scheduler->printError();
		}
		// pop one or none
//		srand(time(NULL));
//		typ = static_cast<StackType> ((rand() % STACK_CNT +1) - 1); // -1 - 2
//		item = scheduler->pop( typ);
//		if(item.getType() == NA) {
//			std::cout << ">> nothing of kind: " << scheduler->printType(typ) << std::endl;
//		}
	}
	std::cout << "summary..." << std::endl;
	
	scheduler->print();
	scheduler->clear(A);
	scheduler->print();
	scheduler->clear(B);
	scheduler->print();
	scheduler->clear(C);
	scheduler->print();
	//scheduler->clear();
	delete[] stosABC;
	return 0;
}
