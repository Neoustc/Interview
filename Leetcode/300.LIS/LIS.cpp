#include <iostream>
#include <string>
#include <vector>
using namespace std;

class solution{
public:
	//computer the LIS and Print
	vector<vector<int> > lengthOfLIS(vector<int>& nums) 
	{
		int n = nums.size();
		vector<int> dp(n, 1);// initial to 1
		int maxlen = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1 );
			}
		maxlen = max(maxlen, dp[i]);
		}
		////////////////////////////////////////////return maxlen
		cout<< " maxlen : " << maxlen <<endl;
		vector<vector<int> > res;
		res = findLIS(nums, dp, maxlen);
		return res;
	}
	vector<vector<int> > findLIS(vector<int>& nums, vector<int>& dp, int maxlen)
	{
		vector<vector<int> > res;
		vector<int> v;
		helper(nums, dp, res, v, maxlen, nums.size() - 1);
		return res;
	}

	void helper(vector<int>& nums, vector<int>& dp, vector<vector<int> >& res, vector<int>& v, int maxlen, int last)
	{
		if (maxlen == 0)
		{
			reverse(v.begin(), v.end());
			res.push_back(v);
			reverse(v.begin(), v.end());// need reverse again
			return;
		}
		for (int i = last; i >= 0; --i)
		{
			if (dp[i] == maxlen && ( v.empty() || nums[i] < v.back())){// v.empty() in the front
			v.push_back(nums[i]);
			helper(nums, dp, res, v, maxlen - 1, i - 1);
			v.pop_back();//pop out the last element.
		}
		}
	}
};
int main(int argc, char const *argv[])
{
	int num[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    vector<int> nums(num, num + sizeof(num) / sizeof(int));
    solution s;
    vector<vector<int> > res = s.lengthOfLIS(nums);
     for (int i = 0; i < res.size(); i++) {
         for (int j = 0; j < res[i].size(); j++)
           cout<< res[i][j]<< " ";
         cout<<endl;
     } 
	return 0;
}
