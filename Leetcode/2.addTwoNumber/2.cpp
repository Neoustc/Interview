    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
  {
  	ListNode head(-1);
  	ListNode * p = & head;
  	int carry = 0;
  	while (l1 || l2 || carry)
  	{
  		carry += l1 ? l1 -> val : 0;
  		carry += l2 ? l2 -> val :0;
  		p -> next = new	 ListNode(carry % 10);
  		carry /= 10;
  		p = p -> next; 
  		l1 = l1 ? l1 -> next : l1;
  		l2 = l2 ? l2 -> next : l2;
  	}
  	return head.next;
  }
