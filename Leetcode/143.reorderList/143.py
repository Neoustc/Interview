class Solution(object):
    def reorderList(self, head):
    	if not head or not head.next:
    		return
    	a, b = _spliList(head)
    	b = _reverseList(b)
    	head = _mergeLists(a, b)

    def _spliList(self, head):
    	fast = head
    	slow = head
    	while fast and fast.next:
    		slow = slow.next
    		fast = fast.next
    		fast = fast.next
    	middle = slow.next
    	slow.next = None
    	return head, middle

    def _reverseList(self,head):
    	last = None
    	currentNode = head
    	while currentNode:
    		nextNode = currentNode.next
    		currentNode.next = last
    		last = currentNode
    		currentNode = nextNode
    	return last

    def _mergeLists(self, a, b):
    	tail = a
    	head = a
    	a = a.next
    	while b :
    		tail.next = b
    		tail = tail.next
    		b = b.next
    		if a :
    			a, b = b, a
    	return head













