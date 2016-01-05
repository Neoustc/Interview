# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        fast = slow = head
        for _ in range(n): # _ it's just a variable like any other, but by convention it means that you don't intend
        #to use that value, just read it and ignore it
        	fast = fast.next
        if not fast:
        	return head.next
        while fast.next:
        	fast = fast.next
        	slow = slow.next
        slow.next = slow.next.next
        return head
        
