# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head :
        	 return False
        slow, fast = head, head
        while fast.next and fast.next.next:
        	slow = slow.next
        	fast = fast.next.next
        	if slow == fast :
        		return True
        return False

//faster,EAFP :  Easier to ask for forgiveness than permission.
than look before you leap : LBYL
        def hasCycle(self, head):
        try:
            slow = head
            fast = head.next
            while slow is not fast:
                slow = slow.next
                fast = fast.next.next
            return True
        except:
            return False
        




        
