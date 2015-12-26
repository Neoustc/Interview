//http://blog.csdn.net/u010738052/article/details/50407889
class Solution{
    public:
	static string letter[] ;
	 vector<string> letterCombinations(string digits) {
	 	int n = digits.size();
	 	vector<string> res;
	 	string s = "";
	 	if (!n) return res;
	 	helper(res, s, digits, 0);
	 	return res;
}
	void helper(vector<string>& res, string& s, string& digits, int start)
	{
		if (start == digits.size())
		{
			res.push_back(s);
			return;
		}
		for (int i = 0; i < letter[digits[start] - '0'].size(); ++i)
		{
			s += letter[digits[start] - '0'][i];
			helper(res, s, digits, start + 1);
			s.pop_back(); 
		}
	}
};
string Solution :: letter[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

***********************************************

