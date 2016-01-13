class Solution {
public:
    bool isAnagram(string s, string t) {
    	unordered_map <char, int> mp;
	int n1 = s.size(), n2 = t.size();
	if (n1 != n2) return false;
	for (int i = 0; i < n1; ++i)
	{
		mp[s[i]]++;
		mp[t[i]]--;
	}
	for (auto e : mp)
		if (e.second) return false;
	return true;
}
};
