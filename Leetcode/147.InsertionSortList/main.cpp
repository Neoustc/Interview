class Solution {
public:
     ListNode* insertionSortList(ListNode* head) {
        ListNode *q=new ListNode(0);
        q->next=head;
        ListNode *cur=head,*p=q;
        while(cur&&cur->next)
        {
        	if(cur->next->val>=cur->val)
        		cur=cur->next;
        	else{
        		ListNode *t=cur->next;
        		cur->next=cur->next->next;
        		while(p&&p->next)
        		{	
        			if(t->val<=p->next->val)
        			{
        				t->next=p->next;
        				p->next=t;
        				p=q;
        				break;
        			}
        			p=p->next;
        		}

        	 }
        }
        return q->next;
    }
};
