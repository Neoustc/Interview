ListNode* insertionSortList(ListNode* head) {
    if (!head || !head -> next) 
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* forward, *tail = head;
        ListNode * p = head -> next;
        while (p) {
            if(p -> val >= tail -> val) {
                tail = tail -> next;
            } else {
                forward = &dummy;
                tail -> next = p -> next;
                while (forward != tail) {
                    if (forward -> next -> val >= p -> val) {
                        p -> next = forward -> next;
                        forward -> next = p;
                        break;
                    } else forward = forward -> next;
                }
            }
            p = tail ->  next;
        }
        return dummy.next;
 }
