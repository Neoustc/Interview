 int maxProduct(vector<string>& words) 
 {
	int n = words.size();
	vector<int> letter(n, 0);
	for (int i = 0; i < n; ++i)
	{
		for (auto c : words[i])
			letter[i] |= (1 << (c - 'a'));
	}
	int maxLen = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			if ((letter[i] & letter[j]) == 0)
			{
				maxLen = max(int(words[i].size() * words[j].size()), maxLen);
			}
		}
		return maxLen;
 }
