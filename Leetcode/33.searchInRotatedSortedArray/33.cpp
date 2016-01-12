//http://blog.csdn.net/u010738052/article/details/50507991
class Solution {
public:
  int search(vector<int>& nums, int target) 
  {
  	int n = nums.size();
  	int l = 0, r = n - 1;
  	while (l < r) 
  	{
  		int m = l + ((r - l ) >> 1);
  		if (nums[m] >= nums[r]) l = m + 1;
  		else if (nums[m] < nums[r]) r = m;
  	}
  
  	int offset = n - l;
  //	cout<<offset<<endl;
  	l = 0; r = n;
  	while (l < r)
  	{
  		int m = l + ((r - l ) >> 1);
  		int newm = (m - offset) % n;
  		if (nums[newm] < target) l = m + 1;
  		else if (nums[newm] > target) r = m;
  		else return newm;
  	}
  return  - 1;
  }

  int search(vector<int>& nums, int target) 
  {
  	int l = 0, r = nums.size() - 1;
  	while (l <= r)
  	{
  		int m = (l & r) + ((l ^ r) >> 1);
  		if (nums[m] == target) return m;
  		if (nums[m] >= nums[l])
  		{
  			if (target >= nums[l] && target <= nums[m])
  				r = m - 1;
  			else 
  				l = m + 1;
  		}
  		else
  		{
  			if (target >= nums[m] && target <= nums[r])
  				l = m + 1;
  			else 
  				r = m - 1;
  		}
  	}
  	return  -1;
  }
};
