//http://blog.csdn.net/u010738052/article/details/50490988
 l is left position of the window
 j is last position of the other char(different with s[i]) in the window 
 Example:    eeceeceegdgg
     		  	 lj  
     		  	 l j 
     		  	 l   j 
     		  	 l    j
     		  	       l j 
 int lengthOfLongestSubstringTwoDistinct(string s) 
 {
 	int l = 0, j = -1, len = 0, n = s.size();
          for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) continue;
              if (j >= 0 && s[i] != s[j]) 
              {
                  len = max(len, i - l);
                  l = j + 1;
              }
            j = i - 1;
         }
         return max(n - l, len);
 }

