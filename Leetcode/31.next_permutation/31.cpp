/*
1.start from its last element,traverse backward to find the first one with index k satisfy
num[k]<num[k+1].So,elements from num[i] to num[n-1] is **reversely sorted**.
2.find the largest index l greater than k such that nums[k]<nums[l];
3.swap the value of nums[k] with that of nums[l];
4.reverse the sequence from nums[k+1] up to and including the final element nums[nums.size()-1];

*/
void nextPermutation(vector<int>& nums) 
 {
 	int n = nums.size();
 	if (n <= 1) return;
 	int j = n - 1;
 	while (j > 0 && nums[j - 1] >= nums[j])
 		j--;
 	if (j == 0)
 		reverse (nums.begin(), nums.end());
 	else {
 	    //cout<<j;
 		int p;
 		for (p = n - 1; p >= j; --p)
 		{
 			if (nums[p] > nums[j - 1])
 				break;
 		}
 		swap(nums[p],nums[j - 1]);
 		reverse(nums.begin() + j, nums.end());
 	}
 }
};
