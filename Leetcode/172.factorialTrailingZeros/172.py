class Solution(object):
     def trailingZeroes(self, n):
        r = 0
        while n > 0:
            n /= 5
            r += n
        return r
        
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
    return 0 if n == 0 else n / 5 + self.trailingZeroes(n / 5)
