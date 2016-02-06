class Solution {
public:
 int lengthOfLongestSubstring(std::string s) {
       std::vector<int> flag(256, -1);
       // int flag[256] = {-1};
       memset(flag, -1, sizeof(flag));
        int start = 0, longest = 0, len = s.size();
        for (int i = 0; i != len; ++i) {
            if (flag[s[i]] >= start) {
                longest = std::max(longest, i - start);
                start = flag[s[i]] + 1;
            }
            flag[s[i]] = i;
        }
        return std::max(longest, len - start);
    }
};
