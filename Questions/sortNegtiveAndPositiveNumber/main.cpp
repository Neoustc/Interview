//http://tech-wonderland.net/blog/interview-questions-sort-negative-and-positive-numbers.html
#include <iostream>
#include <vector>
using namespace std;
/*
make the array leading with the negitive nums
and following with positive nums,but can't change the relative order/sequence  
so quick sort is suitable
*/

//return the first positive  num
// 
void flip(vector<int> &nums, int l, int mid ,int r){
	reverse(nums.begin() + l, nums.begin() + mid);//second parameter is open bracket,this num will be in the front
	reverse(nums.begin() + mid , nums.begin() + r + 1);
	reverse(nums.begin() + l ,nums.begin() + r  + 1);
}
int helper(vector<int> &nums, int left, int right){
	if (left > right) return -1;
	if(left == right){
		if(nums[left] < 0) return -1;
		else return left;
	}
	if(right - left == 1){
		if(nums[right] < 0 && nums[left] > 0)
		{
			swap(nums[left],nums[right]);
			return right;
		}
		if(nums[right] > 0 && nums[left] < 0)
			return right;
		if(nums[right] < 0 && nums[left] < 0)
			return -1;
		return left;
	}
	int mid = left + ((right - left) >> 1);
	int l = helper(nums, left, mid - 1);
	int r = helper(nums, mid, right);
	if(l == -1) return r;
	if(r == -1){
		flip(nums, l, mid, right);
		return right - (mid - l) + 1; 
	}
	flip(nums, l, mid, r - 1);
	return r - (mid -l);
}
void reorder(vector<int> &nums){
	int n = nums.size();
	helper(nums, 0, n - 1);
}

int main(int argc, char const *argv[])
{
	vector<int> v = {1,2,3,-3};
	reorder(v);
	//flip(v, 0, 2, 4);
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
	cout<<(*i)<<" ";
	}
	cout<<endl;
	return 0;
}
