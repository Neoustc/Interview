 // contains dups
// just compare the two ends element
// don't need to consider the parity of the parlindrome
//because if parlindrome is even amount, must contain dups 
//j ... k, if contains dups j,k point to the elements which diff dups
//else j,k point to the same element  
 string longestPalindrome(string s) 
 {
 	int n = s.size();
 	int start = 0, maxlen = 1;
 	for (int i = 0; i < n - maxlen / 2; )
 	{
 		int j = i, k = i;
 		while (k + 1 < n && s[k + 1] == s[k]) k++;//skip dups;
 		i = k + 1;
 		while (j > 0 && k < n - 1 && s[k + 1] == s[j - 1]) {++k, -- j;}
 		int new_len = k - j + 1;
 		if (new_len > maxlen) {start = j, maxlen = new_len;}
 	}
 	return s.substr(start, maxlen);
 }
