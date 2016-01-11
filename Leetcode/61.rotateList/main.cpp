// calculate the length of the list. consider the case that k is larger than lens
class Solution {
public:
      ListNode* rotateRight(ListNode* head, int k) {
        if(!k || !head || !head->next)
            return head;
        ListNode *fast = head;
        int lens = 1;
        while(k--)
        {
            if(fast->next)
            {
                fast = fast->next;
                lens ++;
            }
            else
            {
                fast = head;
                k %= lens;
            }
        }
        if(fast == head)
            return head;
        ListNode *slow = head;
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *newhead = slow->next;
        slow->next = NULL;
        fast->next = head;
        return newhead;
    }
};
