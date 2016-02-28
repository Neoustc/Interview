 bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
 {
    int n = nums.size();
    if (k < 1 || t < 0 || n < 2 ) return false;
    unordered_map<long, long > mp;
    for (int i = 0; i < n ; ++i)
    {
        long reMappedNum = (long) nums[i] - INT_MIN;
        long bucket = reMappedNum / (long(t) + 1);
        if (mp.count(bucket) > 0 || mp.count(bucket - 1) && (reMappedNum - mp[bucket - 1]) <= t || mp.count(bucket + 1) && mp[bucket + 1] - reMappedNum <= t )
                return true;
        if (mp.size() >= k)
        {
            long lastBucket = ((long)(nums[i - k]) - INT_MIN) / ((long) t + 1);
            mp.erase(lastBucket);
        }
        mp[bucket] = reMappedNum;
    }
    return false;
 }
