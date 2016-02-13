     TreeNode* sortedListToBST(ListNode* head)
 {
 	return convert(head, NULL); 	
 }

 TreeNode * convert (ListNode * head, ListNode * end)
 {
 	if (end == head) return NULL;
 	ListNode * m = getMid(head, end);
 	TreeNode * root = new TreeNode (m -> val);
 	root -> left = convert(head, m);
 	root -> right = convert(m -> next, end);
 	return root;
 }

 ListNode * getMid(ListNode * head, ListNode * end)
 {
 	ListNode * fast = head, *slow = head; 
 	while (fast != end && fast -> next != end)
 //	while (fast -> next != end && fast -> next -> next != end) //test case :[1,2]
 	{
 	    cout<<"s"<<endl;
 		slow = slow -> next;
 		fast = fast -> next -> next;
 	}
 	return slow;
 }
