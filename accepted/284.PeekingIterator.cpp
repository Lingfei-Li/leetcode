// 0.52% 2nd group
// c++ class, inheritance
// caching

#include"mytest.h"

class Iterator {
    struct Data;
	Data* data;
public:
//	Iterator() {}
	Iterator(const vector<int>& nums) {}
	Iterator(const Iterator& iter) {}

	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int peekval; 
    bool peekHasNext, peekflag;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        peekflag = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(peekflag == false) {
            peekHasNext = Iterator::hasNext();
            peekval = Iterator::next();
            peekflag = true;
        }
        return peekval;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(peekflag == true) {
            peekflag = false;
            return peekval;
        }
        else {
            return Iterator::next();
        }
	}

	bool hasNext() const {
        if(peekflag == true) {
            return peekHasNext;
        }
        else
            return Iterator::hasNext();
	}
};

int main() {
	srand(time(NULL));




    return 0;
}
