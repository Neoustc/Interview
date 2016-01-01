str: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
dict : a, aa, aaaa,aaaaaaa,aaaaaaaaa;
result : get tle 
class Solution {
public:
   bool wordBreak(string s, unordered_set<string>& wordDict) {
    if(wordDict.size()==0)return false;
 	int n = s.size();
 	if (n == 0 || wordDict.count(s)) return true;
 	for (int i = 0; i < n; ++i)
 	{
 		if (wordDict.count(s.substr(0, i + 1)) > 0)
 		{
 			if (wordBreak(s.substr(i + 1), wordDict))return true;
 		}
 	}
 	return false;
   }
};
