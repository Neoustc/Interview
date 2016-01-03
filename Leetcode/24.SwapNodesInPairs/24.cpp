 ListNode* swapPairs(ListNode* head) 
 {
 	if (!head || !head -> next) return head;
 	ListNode * newhead = new ListNode (-1);
 	newhead -> next = head;
 	ListNode * p = newhead;
 	while (p && p -> next && p -> next -> next)
 	{
 		p -> next = swapNode(p -> next);
 		p = p -> next -> next;
 	}
 	return newhead -> next;
 }

 ListNode * swapNode(ListNode * p)
 {
 	ListNode * t = p -> next;
 	p ->next = p ->next ->next;
 	t -> next = p;
 	return t;
 }
