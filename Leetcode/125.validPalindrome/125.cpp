// isalnum(c) judge a char is a alphanumeric  character or not
// move two pointers from each end until they collide;
// increment left if not alphanumeric
// decrement right ....
// turn them to the Upper case then compare!!


// toupper(c) change the c to  upper letter 
// tolower(c) change  		    lower 
// isalnum() judge whether a c is num or alpha
// The result is true if either isalpha or isdigit would also return true.

// isdigit(),isalpha();
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
