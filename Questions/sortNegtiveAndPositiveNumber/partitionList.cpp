//https://leetcode.com/problems/partition-list/

ListNode* partition(ListNode* head, int x) {
      ListNode * left = new ListNode(-1); 
      ListNode * right = new ListNode(-1);
      ListNode *newhead1 = left, *newhead2 = right; 
      while(head)
      {
      	if(head -> val < x)
      		left = left -> next = head;
      	else 
      		right = right ->next = head;
      	head = head	-> next;
      }
      right -> next = NULL;
      left -> next =  newhead2->next;
      return newhead1 -> next;
    }
    
