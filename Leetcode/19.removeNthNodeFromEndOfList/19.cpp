ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	ListNode newhead(-1);
	ListNode * fast = &newhead;
	newhead.next = head;
	ListNode * slow = &newhead;
	while (n > 0)
	{
		fast = fast -> next;
		--n;
	}
	while (fast -> next)
	{
		fast = fast -> next;
		slow = slow -> next;
	}
	slow -> next = slow -> next -> next;
	return newhead.next;
}
