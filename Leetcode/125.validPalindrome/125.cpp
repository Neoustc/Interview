// isalnum(c) judge a char is a alphanumeric  character or not
class Solution {
public:
    bool isPalindrome(string s) {
	int n = s.size();
	int i = 0, j = n - 1;
	while (i < j)
	{
		while (i < j && !isalnum(s[i])) ++i;
			if (i >= j) break;
		while (i < j && !isalnum(s[j])) --j;
			//if (i >= j) break; 
		if (tolower(s[i++]) != tolower(s[j--]))
			return false;
	}
	return true;
    }
};
