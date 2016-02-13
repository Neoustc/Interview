  ListNode* sortList(ListNode* head) 
  {
  	if (head == NULL || head -> next == NULL) return head;
  	ListNode * slow = head; 
  	ListNode * fast	= head;
  	ListNode * p1 = head;
  	while (fast -> next && fast -> next -> next)
  	{
  		slow = slow -> next;
  		fast = fast -> next -> next;
  	}
  	ListNode * p2 = slow -> next;
  	slow -> next = NULL;
  	ListNode* h1 = sortList(p1);
  	ListNode* h2 = sortList(p2);
  	return mergeSort(h1, h2);
  }

  ListNode * mergeSort(ListNode * p, ListNode * q)
  {
	ListNode dummy(-1); 
	ListNode * tail = &dummy;
  	while (p && q)
  	{
  		if (p -> val < q-> val)
  		{
  			tail -> next = p;
  			p = p -> next;
  		}
  		else {
  			tail -> next = q;
  			q = q -> next;
  		}
  		tail = tail -> next;
  	} 
  	tail -> next = p ? p : q;
  	return dummy.next;
  }
