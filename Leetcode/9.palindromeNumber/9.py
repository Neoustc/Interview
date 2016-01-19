class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 or (x and x % 10 == 0 ) :
        	return False
        p = 0
        while (x > p) :
        	p = p * 10 + x % 10
        	x /= 10
        if x == p or p / 10 == x :
        	return True
        return False
        
