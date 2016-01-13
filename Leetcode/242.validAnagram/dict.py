class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dict = {}
        if len(s) !=  len(t):
            return False
        for i in xrange(len(s)):
        	dict[s[i]] = dict.get(s[i], 0) + 1;
        	dict[t[i]] = dict.get(t[i], 0) - 1;
        for item in dict:
        	if (dict[item]):
        		 return False
        return True
        
