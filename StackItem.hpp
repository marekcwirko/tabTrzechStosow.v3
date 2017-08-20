#ifndef STACKITEM_HPP
#define STACKITEM_HPP

#include <iostream>

#define STACK_CNT 3

enum StackType {
	NA = -1, A, B, C
};

class StackItem {
	
public:
	StackItem() : typ(NA), val(0), next(0), idx(-1), nextIdx(-1) { };
	StackItem(StackType typ, long val, int idx) : typ(typ), val(val), next(0), idx(idx), nextIdx(-1) { };
	
	StackItem(const StackItem& item) {
		this->typ = item.typ;
		this->val = item.val;
		this->next = item.next;
	}
	
	StackType getType() { return typ; };
	long getValue() { return val; }
	long getIdx() { return idx; }
	long getNextIdx() { return nextIdx; }
    
    StackItem* getNext() { return next; }
    void setNext(StackItem *next, int nextIdx) { this->next = next; this->nextIdx = nextIdx; }
    void clear() {typ = NA; val = 0; next=0; idx = -1; nextIdx = -1; }
    
private:
	StackType typ; // descriminator
	long val; // e.g. contents
	StackItem *next; // to follow in stack & computed by scheduler
	int idx; // ctrl
	int nextIdx; // ctrl
};

#endif //ITEM__HPP
