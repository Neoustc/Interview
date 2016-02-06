class Solution {
public:
  int lengthOfLongestSubstring(string s) 
   {
   	int n = s.size();
   	int maxlen = 0;
   	int i = 0, j = 0;
   	//int occur[256] = {0}; all the elements are 0, if = {-1}, first will be -1 others are 0;
   	memset(occur, 256, 0)；
   	for (; j < n; ++j)
   	{
   		if (occur[s[j]])
   		{
   			maxlen = max(maxlen, j - i);
   			while (occur[s[j]] && i < j) {
	   			occur[s[i]] = 0;
	   			i++;
   			}
   		}
        	occur[s[j]] = 1;
   	}
   	//cout<<j<<i;
   	maxlen = max(maxlen, j - i);
   	return maxlen;
    }
};
