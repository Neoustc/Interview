http://blog.csdn.net/u010738052/article/details/50439133

#include <iostream>
#include <vector>
#include <string>
using namespace std;

 string missRanges(int low, int high)
 {
 	return (low == high) ? "" + to_string(low) : to_string(low) + "->" + to_string(high);
 }

 vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) 
 {
 	vector<string> res;
 	int pre = lower - 1, n = nums.size();
 	//pre is the last num in the previous range. 
 	for (int i = 0; i <= n; i++)
 	{
 		int cur = (i == n) ? upper + 1 : nums[i];
 		if (cur - pre >= 2)
 			res.push_back(missRanges(pre + 1, cur - 1));
 		pre = cur;
 	}
 	return res;
 }


 int main(int argc, char const *argv[])
 {
 	vector<int> nums{0, 3, 50, 75};
    vector<string> res = findMissingRanges(nums, -2, 99);
    for (auto s : res)
    	cout << s << endl;
 	return 0;
 }
