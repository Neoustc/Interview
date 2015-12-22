//http://blog.csdn.net/u010738052/article/details/50378488

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> windows;
        for (int i = 0; i < nums.size(); i++) {
            auto pos = windows.lower_bound(nums[i] - t);
            if (pos != windows.end() && *pos <= (long long)nums[i] + t)
                return true;
            windows.insert(nums[i]);
            if (i >= k) windows.erase(nums[i - k]);
        }
        return false;
    }
    
    //size = k + 1; 
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
       int n=nums.size()-1;
       set<int> s;	//ordered automatically
       if(k<=0)return false; 
       if(k>n)k=n;
       for (int i = 0; i <=n; ++i)
       {
       	if(i>k)s.erase(nums[i-k-1]);
       set<int>::iterator lower=s.lower_bound(nums[i]-t);//when s is empty return s.end();
       	if(lower!=s.end()&&abs(*lower-nums[i])<=t)
       		return true;
       	 s.insert(nums[i]);
       }
    }
