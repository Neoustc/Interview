//http://blog.csdn.net/u010738052/article/details/50627589
we keep two heaps, called large and small;
large is a min-heap; which stores the larger half of all numbers   
small is a max-heap; which stores the smaller half of all numbers
Of course the size need to be balanced.
when total size is 2n ; the size of two half is n, n;
when total size is 2n + 1; the smaller half is n + 1, the larger half is n;

addNum :
when a new element comes, we first insert the element to small,pop the maximum item from small then 
push it into large;
After that if the larger half is bigger than the smaller half. 
pop out the minmum element in larger and  insert this 
element to small heap.

findMedian :
if the two heap size is equal,just pop out the two elements and average them,
else pop out the element from small heap. 

****************************************
class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        small.push(num);
        int t = small.top();
        small.pop();
        large.push(t);
        int m = small.size(), n = large.size();
        if (n > m)
        {   	
        	int t = large.top();
        	large.pop();
        	small.push(t);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int m = small.size(), n = large.size();
        if (m == n)
          return (small.top() + large.top()) / 2;
      	else return small.top();
    }

    priority_queue <int, vector<int>, less<int> > small;
    priority_queue <int, vector<int>, greater<int> > large;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
