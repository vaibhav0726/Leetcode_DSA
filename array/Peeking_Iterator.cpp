// Design an iterator that supports the peek operation on an existing iterator in addition to the hasNext and the next operations.
// Implement the PeekingIterator class:
// PeekingIterator(Iterator<int> nums) Initializes the object with the given integer iterator iterator.
// int next() Returns the next element in the array and moves the pointer to the next element.
// boolean hasNext() Returns true if there are still elements in the array.
// int peek() Returns the next element in the array without moving the pointer.
// Note: Each language may have a different implementation of the constructor and Iterator, but they all support the int next() and boolean hasNext() functions.

class PeekingIterator : public Iterator {
private:
    int next_val;
    bool has_next;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    has_next = Iterator::hasNext();
        if(has_next)
            next_val = Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return next_val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int temp = next_val;
        has_next = Iterator::hasNext();
        if(has_next)
            next_val = Iterator::next();
        
	    return temp;
	}
	
	bool hasNext() const {
	    return has_next;
	}
};
