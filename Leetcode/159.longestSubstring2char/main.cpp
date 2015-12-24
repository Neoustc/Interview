// if the size of st is less than 2 or its size is equal to 2
//but the current char is in the st, we insert the char to st. len increment by 1
// when the size of st is 2, and meet another char, we need clear the st, and insert the current 
//char, also we need to reinsert the previous char as much as possible(keep the st has 2 chars).then
//we can move forward    
int lengthOfLongestSubstringTwoDistinct(string s) {
	unordered_set<char> st;
	int n = s.size();
	int maxlen = 0, len = 0;
	for (int i = 0; i < n; ++i)
	{
		if (st.size() < 2 || st.size() == 2 && st.count(s[i]) > 0)
		{
		st.insert(st);
		len++
		}
		else {
			maxlen = max(maxlen, len);
			st.clear();
			int pos = i;
			st.insert(s[i--]);
			len = 1;
			while (i && (st.size() < 2 || (st.size() == 2 && st.count(s[i]) > 0)))
			{
				st.insert(s[i--]);
				len++;
			}
			i = pos + 1;
		}
		return max(maxlen, len);
	}

}
