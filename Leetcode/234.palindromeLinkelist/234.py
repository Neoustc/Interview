// bool False True;
class Solution(object):
     def reverseList(self,head):
    	if not head or not head.next :
    		return head
    	p = head.next
    	head.next = None# python None is NULL
    	while p :
    		t = p.next
    		p.next = head
    		head = p
    		p = t
        return head
        
     def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head or not head.next:
            return True
    	slow = fast = head
    	while fast.next and fast.next.next :
    		fast = fast.next.next
    		slow = slow.next
    	slow.next = self.reverseList(slow.next)//USE self.func to invoke the function
    	slow = slow.next
    	while slow :
    		if head.val != slow.val :
    			return False
    		head = head.next
    		slow = slow.next
        return True
