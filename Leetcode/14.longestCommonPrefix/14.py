class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        sz, ret = zip(*strs), ""
        for c in sz:
        	if len(set(c)) > 1: break
        	ret += c[0]
        return ret
        
