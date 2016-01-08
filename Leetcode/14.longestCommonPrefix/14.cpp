  string longestCommonPrefix(vector<string>& strs) {
   if (strs.empty()) return "";
	string lcp = "";
	int m = strs.size(), n = strs[0].size();
	for (int i = 0; i < n; ++i){
		for (int j = 1; j < m; ++j)
			if (strs[j][i] != strs[0][i] || strs[j].size() == i)
				return lcp;
			lcp += strs[0][i];
	}
	return lcp;
}
