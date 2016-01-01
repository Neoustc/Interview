class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    if (!head) return head;
 	ListNode * newhead = new ListNode (-1);
 	newhead -> next = head;
 	ListNode * start = head -> next;
 	ListNode * tail = head;
 	ListNode * p;
 	tail -> next = NULL;
 	while(start)
 	{
 		if (start -> val >= tail -> val)
 			{
 				tail -> next = start;
 				start = start -> next;
 				tail = tail -> next;
 				tail -> next = NULL;
 			}
 		else {
 		    p = newhead;
 			while(p -> next && start -> val > p -> next -> val)
 				p = p -> next;
 			ListNode * t = start -> next;
 			start -> next = p -> next;
 			p -> next = start;
 			start = t;
 		}
 	}
 	return newhead -> next;
 }
};
