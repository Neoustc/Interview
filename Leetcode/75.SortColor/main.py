# count sort    
def sortColors1(self, nums):
    c0 = c1 = c2 = 0
    for num in nums:
        if num == 0:
            c0 += 1
        elif num == 1:
            c1 += 1
        else:
            c2 += 1
    nums[:c0] = [0] * c0 # c++ could use fill(begin, end, num) function
    nums[c0:c0+c1] = [1] * c1
    nums[c0+c1:] = [2] * c2
    
  *******************************************  
    
    class Solution(object):
    def sortColors(self, nums):
    	"""
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
    	i = j = 0
    	for k in range(len(nums)):
    		v = nums[k]
    		nums[k] = 2
    		if (v < 2) :
    			nums[j] = 1
    			j += 1
    		if (v == 0) :
    			nums[i] = 0
    			i += 1
