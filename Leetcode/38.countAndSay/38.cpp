class Solution {
public:
string countAndSay(int n) 
{
	string s = "1";
	if (n == 1) return s;
	for (int i = 1; i < n; ++i)
	{
		s = gen(s);
	}
	return s;
}

string gen(string & s)
{
	string v = "";
	int n = s.size();
	int count = 0;
	for (int i = 0; i < n;++i)
	{
	    count = 1;
		if ((i + 1) < n && s[i] == s[i + 1])
		{
			while ((i + 1) < n && s[i] == s[i + 1])
			{
				count ++ ;
				i++;
			}
		}
	v += to_string(count) + (s[i]);
		
	}
	return v;
}
};
