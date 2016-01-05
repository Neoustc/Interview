ListNode* removeNthFromEnd(ListNode* head, int n) 
{
  ListNode * fast = head;
	ListNode * slow = head;
	while (n > 0)// the difference should be the same
	{
		fast = fast -> next;
		--n;
	}
	if (! fast) return head -> next;
	while (fast -> next)
	{
		fast = fast -> next;
		slow = slow -> next;
	}
	slow -> next = slow -> next -> next;
	return head;
}
