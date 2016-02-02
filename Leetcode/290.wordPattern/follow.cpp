 Problem Description:

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:

pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false. 
Notes:
You may assume both pattern and str contains only lowercase letters.
**************************************************************
//https://leetcode.com/discuss/63252/share-my-java-backtracking-solution
 bool wordPatternMatch(string pattern, string str) 
 {
 	unordered_map<char, string> mp;
 	set<string> st;
 	return isMatch(str, 0, pattern, 0, map, set);
 }

bool isMatch(string str, int i, string pat, int j, unordered_map<char, string>& mp, set<string> & st)
{
	if (i == str.size() && j == pat.size())return true;
	if (i == str.size() || j == pat.size()) return false;
	char c = pat[j];//store thr current pattern character
	if (mp.find(c) != mp.end()) // already in the map
	{
		string s = mp[c];
		if (s != str.substr(i, s.size())) // check the string after is match or not
			return false;
		else return isMatch(str, i + s.size(), pat, j + 1, mp, st)
	}
//pattern character does not exist in the map;
	for (int len = 1; len < str.size() - i; len++)
	{
		string p = str.substr(i, len);
		if (st.count(p)) continue;
		//create and update
		mp[c] = p;
		set.insert(p);
		if (isMatch(str, i + len, pat, j + 1, mp, st))
			return true;
		//backtracking 
		mp.erase(c);
		set.erase(p);//(logn) BST 
	}
	return false;
}	
