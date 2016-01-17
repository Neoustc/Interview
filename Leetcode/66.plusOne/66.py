class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
    	i = 0
    	for i in range(len(digits) - 1, -1, -1):// start, stop, step.
    		if digits[i] == 9:
    			digits[i] = 0
    		else :
    			digits[i] += 1
    			return digits
    	if i == 0 :
    		#digits.insert(0, 1);
    		digits = [1] + digits#faster
    	return digits;
        
