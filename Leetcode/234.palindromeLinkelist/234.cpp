 bool isPalindrome(ListNode* head) 
 {
 	if (!head || !head -> next) return true;
 	ListNode * slow, *fast;
 	slow = head;
 	fast = head;
 	while (fast -> next && fast -> next -> next)
 	{
 		fast = fast -> next -> next;
 		slow = slow -> next;
 	}
 	slow -> next = reverseList(slow -> next);
 	slow = slow -> next;
 	while(slow)
 	{
 		if (head -> val != slow -> val)
 			return false;
 		head = head->next;
 		slow = slow -> next;
 	}
 	return true;
 }

 	ListNode * reverseList (ListNode * head)
 	{
 		if (!head || !head -> next) return head;
 		ListNode * p = head -> next;
 		head ->next = NULL;
 		while (p)
 		{
 			ListNode * t = p -> next;
 			p -> next = head;
 			head = p;
 			p = t;
 		}
 		return head;
 	}
