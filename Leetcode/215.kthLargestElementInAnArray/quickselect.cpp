avg quick select
T(n) = T(n / 2) + O(n);
T(n) = O(n);
worst:
T(n) = T(n - 1) + O(n);
quick sort
T(n) = 2T(n / 2) + O(n)
T(n) = O(nlogn);

class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) 
 {
 	int n = nums.size();
 	int left = 0, right = n - 1;
 	while (true)
 	{
 	int pos = partition(nums, left, right);
 	if (k - 1 == pos) return nums[pos];
 	if (pos > k - 1) right = pos - 1;
 	else left = pos + 1;
 	}
 }
 int partition (vector<int> & nums, int left, int right)
 {
 	int pivot = nums[left];
 	int l = left + 1, r = right;
//  	while (l <= r)
//  	{
//  		if (nums[l] < pivot && nums[r] > pivot)
//  		swap(nums[l++], nums[r--]);
//  		if (nums[l] >= pivot) l++;
//  		if (nums[r] <= pivot) r--;
//  	}
    while (l <= r )
 	{
    	while (l <= r && nums[l] >= pivot ) l++;
 		if(l <= r) swap(nums[r--], nums[l]);
 		while (l <= r && nums[r] <= pivot ) r--;
 		if(l <= r) swap(nums[l++], nums[r]);
 	}
 	swap(nums[left], nums[r]);// [1]: l = 1, r = 0;
 	return r;
 }
};
