//it's like a slifing window solution;
//because the inner while loop executes at most once for each starting position ;
// the inner while loop runs at most N times during the whole for loop from 0 to nums.size() - 1; 
           
int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int l = 0, sum = 0;
        int length = n + 1;
    for (int r = 0; r < n; ++r)
    {
        if (nums[r] >= s) return 1;
        sum += nums[r];
        while (sum >= s) {//try to find the mininum length.keep decreasing the length until the length < s;
            length = min(length, r - l + 1);
            sum -= nums[l++];
        }
    }
    return length == n + 1? 0 : length;
}
