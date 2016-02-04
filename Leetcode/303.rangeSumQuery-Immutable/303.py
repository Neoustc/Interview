class NumArray(object):
    def __init__(self, nums) :
    	self.dp = [0]
    	for i in nums :
    		self.dp += self.dp[-1] + i,
    		#self.dp += [self.dp[-1] + i]

    def sumRange(self, i, j) :
        return self.dp[j + 1] - self.dp[i]
