// One thing needs to be mentioned is that when asked to find maximum substring, 
// we should update maximum after the inner while loop to guarantee that the substring is valid.
// On the other hand, when asked to find minimum substring, 
// we should update minimum inside the inner while loop.
 int lengthOfLongestSubstring(string s) {
        vector<int> mp(128, 0);
        int n = s.size();
        if (n == 0) return 0;
        int start = 0, end = 0, maxLen = 0, counter = 0;
        while (end < n)
        {
            if (mp[s[end]] > 0)
                counter++;
            mp[s[end]]++;
                end++;
            while (counter > 0)
                {
                    if (mp[s[start]] > 1)
                        counter --;
                    mp[s[start]]--;
                    start++;
                }
            if (end - start > maxLen)
                maxLen = end - start;
        }
        if (start == 0) return n;
        return maxLen;
    }
