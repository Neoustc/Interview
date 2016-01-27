ListNode* reverseBetween(ListNode* head, int m, int n)
{
	ListNode dummy(-1);
	if (!head || m == n) return head;
	ListNode * p = &dummy;
	dummy.next = head;
	int i = 1;
	while (i < m)
		{
			p = p -> next;
			++i;
		}
	ListNode * h = p -> next;
	p -> next = NULL;
	ListNode * tail = h;
	ListNode * t = h -> next;
	while (i < n)
	{
		ListNode* next = t -> next;
		t -> next = h;
		h = t;
		t = next;
		++i;
	}
	p -> next = h;
	tail -> next = t;
	return dummy.next;
}
