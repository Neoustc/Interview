unordered_map<char, char> mp;
mp = {{'0', '0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}};

int findStrobogrammaticNumber(string low, string high) {
	int ans = 0, l = low.size(), u = high.size();  
	for (int i = l; i <= u; ++i){
		string  temp(i, ' ');
		strobogrammaticCount(temp, ans, low, high, 0, i - 1);
    }
    return ans;
}

void strobogrammaticCount(string temp, int & ans, string & low, string & high, int lo, int hi)
{
	if (lo > hi)
	{
		if ((temp[0] != '0' || temp.size() == 1) && temp.compare(low) > 0 && temp.compare(high) < 0)
			ans++;
		return;
	}	
for (auto m : mp)
{
	temp[lo] = m.first;
	temp[hi] = m.second;
	if (lo == hi && m.first == m.second || lo < hi)
		strobogrammaticCount(temp, ans, low, high, lo + 1, hi - 1);

}
}

