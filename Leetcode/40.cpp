class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    	std::vector< vector<int> > res;
        std::vector<int> v;
        sort(candidates.begin(),candidates.end());
        combine(candidates,target,res,v,0);
        return res;
    }
void combine(vector<int>& candidates,int target,vector< vector<int> > &res,vector<int> & v,int begin)
    {
    	if(target==0)
    	{
    		res.push_back(v);
    		return;	
    	}
    	for (int i = begin; i < candidates.size()&&candidates[i]<=target; ++i)
    	{
    		if(i==begin||candidates[i]!=candidates[i-1]){
    		v.push_back(candidates[i]);
        	combine(candidates,target-candidates[i],res,v,i+1);
    		v.pop_back();
    		    
    		}
    	}

    }
};
