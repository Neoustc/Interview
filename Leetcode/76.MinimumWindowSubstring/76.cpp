 string minWindow(string s, string t) {
     int n = s.size(), m = t.size();
     vector<int> mp(128, 0);
     for(auto c : t) mp[c]++;
     int start = 0, end = 0, minStart = 0, minLen = INT_MAX, count = m;
     while (end < n)
         {
            if (mp[s[end]] > 0) count--;
            mp[s[end]]--;
            end++;
            while (count == 0)
            {
                if (end - start < minLen)
                  {  
                      minStart = start;         
                      minLen = end - start;
                  }
                  if (mp[s[start]] == 0)
                    count++;
                  mp[s[start++]]++;
            }
         }
         if (minLen == INT_MAX) return "";
         return s.substr(minStart, minLen);
    }
