int strStr(string haystack, string needle) {
	int n = haystack.size(), m = needle.size();
	if (m > n) return -1;
	for (int i = 0; i <= n - m; ++i){
	    int j = 0,index = i;
		for (;j < m; ++j)
		{
			if (needle[j] != haystack[index++])
				break;
		}
		if (j == m) return i;
	}
	return -1;
}
