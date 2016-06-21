#include <iostream>
#include <vector>
using namespace std;

void mergeArray(vector<int> & nums, int l, int m, int r) {
	vector<int> tmp(r - l + 1);
	int i = m + 1, j = l, idx = 0;
	while (j <= m && i <= r){
		if (nums[j] < nums[i]){
			tmp[idx++] = nums[j++];
		} else {
			tmp[idx++] = nums[i++];
		}
	}

	while (i <= r){
		tmp[idx++] = nums[i++];
	}
	while (j <= m) {
		tmp[idx++] = nums[j++];
	}

	for(int i = l; i <= r; ++i){
		nums[i] = tmp[i - l];
	}
}
void mergeSort(vector<int>& nums, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(nums, l, m);
		mergeSort(nums, m + 1, r);
		mergeArray(nums, l, m, r);
	}
}
int main(int argc, char const *argv[])
{
	vector<int> nums{1,2,3,2,0,1,1,2,6,0,8,7,10};
	mergeSort(nums, 0, nums.size() - 1);
	for (auto i : nums) {
		cout << i << " ";
	}
	return 0;
}

