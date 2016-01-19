 //find the target or the first one greater than target.
 class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     int n = nums.size();
 	int low = 0, high = n;
 	int mid = 0;
 	// answer is [0,n] or [low, high]
 	while (low < high)
 	{
 		mid = low + ((high - low ) >> 1);
 		if (nums[mid] == target) return mid;
 		if (nums[mid] < target) low = mid + 1;//[low(mid + 1), high];
 		else high = mid;
 	}
 	// low >= high , at this point
 	// low <= high; invariant 
 	// so : low = high; 
 	return low;// or return high; 
    }
};
