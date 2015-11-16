//https://leetcode.com/problems/combination-sum/

class Solution {
public:
   vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    	sort(candidates.begin(),candidates.end());
    	vector< vector <int> > res;
    	vector<int> v;
    	if(target<candidates[0]||candidates.size()==0)return res;
    	combine(candidates,res,v,target,0);
    	return res;
    }
    
    void combine(vector<int>& candidates,std::vector<vector<int> >& res,vector<int> &v,int target,int begin)
    {
    	if(target==0)
    	{
    		res.push_back(v);
    		return;
    	}
    	for(int i=begin;i<candidates.size()&&candidates[i]<=target;i++)
    	{
    		v.push_back(candidates[i]);
    		combine(candidates,res,v,target-candidates[i],i);
    		v.pop_back();
    	}
    }
};
