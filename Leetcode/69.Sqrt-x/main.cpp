// using binary search 
// to avoid the overflow we can't use m * m < x; we need use divide.
// initial the loop invariant is [1,x) when enter the while loop. since the l < r - 1; else if set l < r, low = mid will cause
// infinite loop.


int mySqrt(int x) {
    	if (x == 0) return 0;
    	int l = 1, r = x;
    	while (l < r - 1)
    	{
    		int m = l + ((r - l) >> 1);
    		if (x / m < m ) r = m;
    		else if (x / m == m)  return m;
    		else l = m; 
    	}
    	return l;
    }
