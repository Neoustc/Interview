 ListNode * deleteDuplicates(ListNode* head) 
 {
 	if (head == NULL || head -> next == NULL) return head;
 	ListNode * dummy = new ListNode (0);
 	dummy -> next = head;
 	ListNode * pre = dummy, * tail = dummy, *cur = head;
 	while (cur) // cur  pre
 	{
 		while (cur -> next && cur -> val == cur -> next -> val)
 		    	cur = cur -> next;
 		if ( pre -> next == cur)
 		{
 		     tail -> next = cur;
 		     tail = tail -> next;
 		}
 		    pre = cur;
 		    cur = cur -> next;
 	}
    tail -> next = NULL;
    return dummy-> next;
 }
