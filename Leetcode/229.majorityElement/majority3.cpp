//Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array. 
//There is only one majority number in the array. 
//Challenge 
//O(n) time and O(k) extra space
int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, int> mp;
        for (auto num : nums)
        {
            if(mp.find (num) != mp.end()) 
                mp[num]++;
            else
            {
                if (mp.size() < k)
                {
                    mp[num]++;   
                }
                else {
                     vector<int> v;
                    for (auto i : mp)
                      {
                           i.second--;
                        if (i.second == 0)
                         v.push_back(i.first);
                      }
                      for (int i : v)
                      mp.erase(i);
                }
            }
        }

        for (auto i : mp)
           i.second = 0;
        int maxcount = 0;
        int maxkey = 0;
        for (auto i : nums)
        {
            if(mp.find(i) == mp.end())continue;
                mp[i]++;
            if(maxcount < mp[i])
              {
                  maxcount = mp[i];
                  maxkey = i;
              }
        }
        return maxkey;
    }
};
