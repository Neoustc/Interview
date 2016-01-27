// set cur to be the immediate node after pre, and at each time move the immediate node 
// after cur(move) to be the pre -> next.repeat n - m times;
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	ListNode * new_head = new ListNode (0);
	new_head -> next = head;
	ListNode * pre = new_head;
	for (int i = 1; i < m; ++i)
		pre = pre -> next;
	ListNode * cur = pre -> next;
	for (;i < n; ++i)
	{
		ListNode * move = cur -> next;
		cur -> next = move -> next;
		move -> next = pre -> next;
		pre -> next = move;
	}
	return new_head -> next;
}
