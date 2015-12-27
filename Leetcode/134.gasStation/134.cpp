 int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      	int n = gas.size();
      	int i = 0, s = 0;
       while(s < n) {
        int pre(0),cur(0); 
        if (gas[s] < cost[s]) { s++; continue;}  
        for (i = 0; i < n; i++)
        {
        	cur = pre + gas[(s + i) % n] - cost[(s + i) % n];
        	if(cur < 0) break; 
        	else pre = cur;
        }
        if(i == n) return s ;
        s = s + i;
    	}
    	return -1;  
    }
    
    //////o(n) solution 
      class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start(0),total(0),tank(0);
        //if car fails at 'start', record the next station
        for(int i=0;i<gas.size();i++) 
        if((tank=tank+gas[i]-cost[i])<0)
        {
            start=i+1;
            total+=tank;
            tank=0;
            
        }
        return (total+tank<0)? -1:start;
    }

};
