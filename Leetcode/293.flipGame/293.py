# python does not support modifying a string,
# so we only use list and join to do the same thing.
class Solution(object):
    def generatePossibleNextMoves(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = []
        s = list(s)
        for i in xrange(len(s)) :
        	if s[i] == s[i + 1] == '+'
        	s[i] = s[i + 1] = '-'
        	res += ''.join(s), #add a string to list
        	s[i] = s[i + 1] = '+'
        return res
