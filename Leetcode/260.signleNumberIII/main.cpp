class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       int n = nums.size();
       int diff = 0;
       /* std::minus<int>()
		int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
       */
       for(int i : nums)
       diff ^=i;
       diff &= - diff;//get the rightmost bit  which is 1 
       // or use diff & ~(diff - 1) 
       // and -diff = ~diff + 1;
       vector<int > res(2, 0);
       for ( int  i : nums)
       {
       	if((diff & i ) == 0)
       		res[0] ^= i;
       	else res[1] ^= i;
       }
       return res;

    }
};
