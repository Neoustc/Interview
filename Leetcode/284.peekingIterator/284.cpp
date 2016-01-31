class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
     int num; 
	 bool flag;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	   flag = 0;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	  if (flag == 0) 
    	{
    		num = Iterator :: next();
    		flag = 1;
    		return num;
    	}
    	else return num;

	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (flag == 1) 
		        {
		        flag = 0;
				return num;
		        }
		flag = 0;
	    return Iterator :: next();
	}

	bool hasNext() const {
	   // if (flag == 1) return true;
	    return Iterator :: hasNext() || flag;
	}
};
