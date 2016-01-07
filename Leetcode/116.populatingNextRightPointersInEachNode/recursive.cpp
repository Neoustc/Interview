 void connect(TreeLinkNode *root)
    {
 	if (root == NULL) return;
 	if (root -> left) {
 		root -> left -> next = root -> right;
 		if (root -> next)
 			root -> right -> next = root -> next -> left;
 	}
 	connect(root -> left);
 	connect(root -> right);
    }
