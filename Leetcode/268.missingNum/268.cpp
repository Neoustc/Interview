//math
   int missingNumber(vector<int> & nums)
  {
 	int sum = accumulate(nums.begin(), nums.end(), 0);
 	int res = nums.size()* (nums.size() + 1) / 2; 
 	return res - sum;
  }


   int missingNumber(vector<int> & nums)
 {
 	int n = nums.size(), ans = n * (n + 1) / 2;
 	for (int num : nums) ans -= num;
 	return ans;
 }

 //***
//bit manipulation
 int missingNumber(vector<int> & nums)
 {
 	int n = nums.size();
 	int res = 0, i = 0;
 	for (int num : nums)
 	{
 		res ^= num;
 		res ^= i++; 
 	}
 	return res;
 }
 ****
