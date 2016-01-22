class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        slow = self.digitSquare(n)
        fast = self.digitSquare(slow)
        while slow != 1 :
            if (slow == fast) :
                return False
            slow = self.digitSquare(slow)
            fast = self.digitSquare(self.digitSquare(fast)) 
        return True
        
    def digitSquare(self, n):
        res = 0
        while n > 0 :
            res += (n % 10) * (n % 10)
            n /= 10
        return res
            
        
