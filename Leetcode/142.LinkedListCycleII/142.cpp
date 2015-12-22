 ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head -> next == head) return head;
   	ListNode* slow = head, *fast = head;
   	while (fast -> next && fast -> next -> next)
   	{
   		slow = slow -> next;
   		fast = fast -> next -> next;
   		if (slow == fast) break;
   	}
   	if (!fast -> next || !fast -> next -> next ) return NULL;
   	fast = head;
   	while (fast != slow )
   	{
   		fast = fast -> next;
   		slow = slow -> next;
   	}
   	return slow;
   }
   
  __________________________________________________________________________________________________________ 
    ListNode *detectCycle(ListNode *head) {
   	ListNode* slow = head, *fast = head;
   	while (fast && fast -> next)//condition is much simple
   	{
   		slow = slow -> next;
   		fast = fast -> next -> next;
   		if (slow == fast)
   		{
   			fast = head;
	   		while (fast != slow )
		 	{
				fast = fast -> next;
				slow = slow -> next;
		  	}
  	 		return slow;
   		}
   	}
   	return NULL;  
}
