//http://blog.csdn.net/u010738052/article/details/50455244
 ListNode* reverseKGroup(ListNode* head, int k) {
 	if (!head || !head -> next || k == 1) return head;
 	ListNode * newhead = new ListNode (-1);
 	ListNode * p = newhead;
 	newhead -> next = head;
 	while (p){
 	ListNode *t = p;
 	for (int i = 0; i < k && t; i++)
 		t = t -> next;
 	if (!t) return newhead -> next;
 	p = swapNode(p, k);
 	}
 	return newhead -> next;
 }
 	ListNode* swapNode(ListNode *p, int k)
 	{
 		ListNode * tail = p -> next;
 		ListNode * q = tail -> next;
 		for (int i = 1; i < k; ++i)
 		{
 			tail -> next = q -> next;
 			q -> next = p -> next;
 			p -> next = q;
 			q = tail -> next; 
 		}
 		return tail;
 	}
