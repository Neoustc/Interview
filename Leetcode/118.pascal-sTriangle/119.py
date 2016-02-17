class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        l=[0]*(rowIndex+1)
        l[0]=1
        for i in range(1,rowIndex+1):
        	for j in range(i,0,-1):
        		l[j]+=l[j-1]
        return l;
