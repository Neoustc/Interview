classic hast table problem;
we could use unordered_map or unordered_set to solve the problem
***********************
// 48ms
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> st; 
      for (int i : nums)
            if (st.count(i) == 0)
                  st.insert(i);
            else return true;
      return false;
      /*
        if (st.find(nums[i]) != st.end())
            return true;
            st.insert(nums[i]);
      */
      
    }
}
//one line code but  52ms; probably sets are implemented as binary search trees;
//insert not constant time.

   return nums.size() > set<int>(nums.begin(), nums.end()).size();   
   
 bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,int>mp;
    	for(int i:nums)
    	{
    		if(++mp[i]>1)
    			return true;
    	}
    	return false;
    }



