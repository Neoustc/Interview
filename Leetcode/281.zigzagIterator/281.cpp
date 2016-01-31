//http://www.cnblogs.com/jcliBlogger/p/4807033.html
class ZigzagIterator {
private:
	int p;
	vector<int> :: iterator bs[2], es[2];	
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        bs[0] = v1.begin();
        bs[1] = v2.begin();
        es[0] = v1.end();
        es[1] = v2.end();
    }

    int next() {
       int elem;
       if (bs[0] == es[0]) elem = *bs[1] ++;
       else if (bs[1] == es[1]) elem = *bs[0]++;
       else {
       	elem = *bs[p] ++;
       	p = (p + 1) % 2;
       }
       return elem;
    }

    bool hasNext() {
       return bs[0] != es[0] || bs[1] != es[1]; 
    }
};
