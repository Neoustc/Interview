 ListNode* partition(ListNode* head, int x) 
 {
 	ListNode * left = new ListNode (-1);
 	ListNode * right = new ListNode (-1);
 	ListNode * p = left, * q = right;
 	while (head)
 	{
 		ListNode * next = head -> next;
 		head -> next = NULL;
 		if (head -> val < x)
 			{
 				p -> next = head;
 				p = p -> next;
 			}
 		else {
 			q -> next = head;
 			q = q ->next;
 		}
 		head = next;
 	}
 	p -> next = right -> next;
 	return left -> next;
 }
