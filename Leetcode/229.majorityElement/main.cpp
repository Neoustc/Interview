class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> major; 
        unordered_map<int, int> counts;
        unordered_set<int> exist;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            counts[nums[i]]++;
            if (counts[nums[i]] > n / 3 && exist.find(nums[i]) == exist.end()) {
                major.push_back(nums[i]);
                exist.insert(nums[i]);
            }
            if (major.size() == 2) break;
        }
        return major;
    }
};
