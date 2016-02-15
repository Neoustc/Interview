ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)return NULL;
        ListNode *p=headA;
        ListNode *q=headB;
        while(p!=q)
        {
            if(p)p=p->next;
            else p=headB;

            if(q)q=q->next;
            else q=headA;
            if(p==NULL&&q==NULL)return NULL;//CAUTION!the two pointers point to the NULL at the same time!
        }
        return p;
    }

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1=headA;
        ListNode *p2=headB;
        if (p1 == NULL || p2 == NULL) return NULL;
        while(p1&&p2&&p1!=p2){
        	p1=p1->next;
        	p2=p2->next;
        	/*
anytime  they collide or reach the end same time without colliding 
they return any one of the pointers.

if one of the them reaches to the end earlier then reuse it by moving it to the 
beginning of other list.once both of them go through reassigning,they will be equidistant
from the collision point.

        	*/
        	if(p1==p2)return p1;
        	if(p1==NULL)p1=headB;
        	if(p2==NULL)p2=headA;
        }
        return p1;
    }
};
