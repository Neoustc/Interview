class Solution {
public:
    int lengthOfLastWord(string s) {
       int n = s.size();
	int i = n - 1;
	for (; i >= 0 && s[i] == ' '; --i){}
	int p = i;
	for (; s[i] != ' ' && i >= 0; --i){}
	return p - i;
    }
};
