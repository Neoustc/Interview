class Solution {
	struct node
	{
		long val;
		int idx, prim;
		//value, index, primes (2,3,5);
		node(long v = 0, int i = 0, int p = 0) : val(v), idx(i), prim(p){}
		inline bool operator< (const node & x) const{
			return  val > x.val; // min heap
		}
	};
	public:
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	priority_queue<node> q;
    	vector<long> res (n, 0);
    	res[0] = 1;
    	for (int i : primes)
    		q.push(node(i,0,i));
    	for(int i = 1; i < n ; ++i)
    	{
    		node ret = q.top();
    		res[i] = ret.val;
    		while(true){
    			ret = q.top();q.pop();
    			ret.val = res[++ret.idx] * ret.prim;
    			q.push(ret);// push a larger new elements 
    			if(/*q.empty()*/ || q.top().val != res[i]) break;//check whether the value is equal;
    		}
    	}
    	return res[n - 1];
    }
	};

