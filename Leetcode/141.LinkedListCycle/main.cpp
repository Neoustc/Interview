 //maintain two pointers, one move one step at a time and the other move two steps at a time. 
 //If they become the same, a cycle exists. 
 //Otherwise, they will become NULL finally and there is no cycle.
 bool hasCycle(ListNode *head) {
    		if (head == NULL) return 0;
   	ListNode * slow = head;
   	ListNode * fast = head;
   	while (fast ->next && fast -> next -> next)
   	{
   		slow = slow -> next;
   		fast = fast -> next -> next;
   		if ( slow == fast) return true;
   	}
   	return false;
    }
