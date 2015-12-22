//sliding windows size k. Contain unique values from nums[i-k] to nums[i-1];

 bool containsNearbyDuplicate(vector<int>& nums, int k) {
 			unordered_set<int> s;		
 			if(k<=0)return false;
 			if(k>=nums.size())k=nums.size()-1;
 			for (int i = 0; i < nums.size(); ++i)
 			{
 				if(i>k)s.eraser(nums[i-k-1]);
 				if(s.find(nums[i])!=nums.end())return true;
 				s.insert(nums[i]);
 			}
 			return false;
 }
