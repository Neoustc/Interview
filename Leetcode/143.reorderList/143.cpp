 void reorderList(ListNode *head) 
 {
 	if (!head || !head -> next) return; 
 	//find the middle node o(n);
	ListNode * slow = head, fast = head;
	while (fast -> next && fast -> next -> next)
	{
		slow = slow -> next;
		fast = fast -> next -> next;	
	}
	//cur from the middle and reverse the second half;
	ListNode * head2 = slow -> next; 
	slow -> next = NULL;

	fast = head2 -> next;
	head2 -> next = NULL;
	while (fast)
	{
		slow = fast -> next;
		fast -> next = head2;
		head2 = fast;
		fast = slow;
	}
	slow = head;
	fast = head2;
//slow is the current tail of listnode, fast is next node  tmp the next next node; 
	while (slow)
	{
		ListNode* tmp = slow -> next;
		slow -> next = fast;
		slow = slow -> next;
		fast = tmp;
	}
}
