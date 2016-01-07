 void connect(TreeLinkNode *root) 
{
	if (root == NULL) return;
	TreeLinkNode * head = NULL;// head node of next level
	TreeLinkNode * prev = NULL;//leading node in the next level
	TreeLinkNode * cur = root;// current node of current level 
	while (cur)
	{
		while (cur)
		{
			if (cur -> left)//left child
			{
				if (prev)
					prev -> next = cur -> left;
				else 
					head = cur -> left;// if prev do not exist, we set the head; 
				prev = cur -> left;// prev is is current node's left child.
			}
			if (cur -> right)
			{
				if (prev)
					prev ->next = cur -> right;
				else 
					head = cur -> right;
				prev = cur -> right;
			}
			cur = cur -> next;
		}
		cur = head;
		prev = NULL;
		head = NULL;
	}
}
