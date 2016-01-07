# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root :
		    return False
    	stack = [(root, sum)]
    	while stack:
    		node, _sum = stack.pop()
    		if not node.left and not node.right and node.val == _sum:
    			return True
    		if node.left:
    			stack.append((node.left, _sum - node.val))
    		if node.right:
    			stack.append((node.right, _sum - node.val))
    	return False  
