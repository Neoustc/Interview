class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return NULL;
        ListNode * p = head;
        int len = 1;
        while(p->next)
        {
        	p = p->next;
        	len ++; 
        }
        p->next = head;//circle the link
        if(k %= len)
        {
        	for(auto i = 0; i < len - k; i++)
        	{
        		p = p->next;
        	}
        }
        head = p->next;
        p->next = NULL;
        return head;
    }

     ListNode* rotateRight(ListNode* head, int k) {
     	if(!k || !head || !head->next)
            return head;
        ListNode * fast = head;
        int lens = 1;
        while(k-- )
        {
        	if(fast->next){
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
        ListNode * slow = head;
        while(fast->next)
        {
        	fast = fast->next;
        	slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
     }
};
