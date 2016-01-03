// think about the TLE
//http://blog.csdn.net/u010738052/article/details/50453688
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty())return NULL;
    	while (lists.size()>1)
    	{
    		lists.push_back(merge2Lists(lists[0],lists[1]));
    		lists.erase(lists.begin());
    		lists.erase(lists.begin());
    	}
    	/*
    	for (int i = 0; i < lists.size(); ++i)
    	{
    		start=merge2Lists(start,lists[i]);
    	}
    	return start->next;
    	*/
    	return lists.front();
    	

    }

    ListNode * merge2Lists(ListNode *s1,ListNode *s2)
    {
    	if(s1==NULL)return s2;
    	if(s2==NULL)return s1;

    	if(s1->val<=s2->val) 
			 {
			 	s1->next=merge2Lists(s1->next,s2); 
				return s1;
			}
		 else 
		 {
		 	s2->next=merge2Lists(s1,s2->next); 
		 	return s2;
		 }
    }
};
