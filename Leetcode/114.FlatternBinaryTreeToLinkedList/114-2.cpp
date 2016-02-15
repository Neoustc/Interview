  void flatten(TreeNode* root) 
 {
 	if (!root) return;
 	flatten(root -> left);
 	TreeNode * t = root -> right;
 	root -> right = root -> left;
 	root -> left = NULL;
 	flatten(t);
 	while (root -> right)
 	{
 		root = root -> right;
 	}
 	root -> right = t;
 	return;
 }
