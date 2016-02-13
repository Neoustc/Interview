 ListNode* sortList(ListNode* head) 
{
	if (head == NULL || head -> next == NULL) return head;
	
	ListNode dummys (-1), dummye(-1), dummyl(-1);
	ListNode * small = &dummys;
	ListNode * equal = &dummye;
	ListNode * large = &dummyl;
	ListNode * cur = head;
	while (cur)
	{
		if (cur -> val < head -> val)
		{
			small -> next = cur;
			small = small -> next; 
		}
		else if (cur -> val == head -> val)
		{
			equal -> next = cur;
			equal = equal -> next;
		}
		else {
			large -> next = cur;
			large = large -> next;
		}
		cur = cur ->next;
	}
		small -> next = NULL;
		equal -> next = NULL;
		large -> next = NULL;
	return merge(merge(sortList(dummys.next), sortList(dummyl.next)), dummye.next);
}
ListNode * merge(ListNode * p, ListNode * q)
  {
	if (p == NULL) return q;
	if (q == NULL) return p;
    if (p -> val < q -> val){
    	p->next = merge(p->next, q);
    	return p;
    }
    else{
    	q -> next = merge(p, q->next);
    	return q;
    }
  }
//   ListNode * merge(ListNode * p, ListNode * q)
//   {
// 	ListNode dummy(-1); 
// 	ListNode * tail = &dummy;
//   	while (p && q)
//   	{
//   		if (p -> val < q-> val)
//   		{
//   			tail -> next = p;
//   			p = p -> next;
//   		}
//   		else {
//   			tail -> next = q;
//   			q = q -> next;
//   		}
//   		tail = tail -> next;
//   	} 
//   	tail -> next = p ? p : q;
//   	return dummy.next;
//   }
