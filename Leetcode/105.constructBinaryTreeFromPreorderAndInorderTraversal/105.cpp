TreeNode* buildTree (vector<int>& preorder, vector<int>& inorder) 
 {
 	int m = preorder.size();
 	int n = inorder.size();
 	return build (preorder, 0, m - 1, inorder, 0, n - 1);
 }
 
 TreeNode * build (vector<int>& preorder, int p1, int p2, vector<int>& inorder, int i1, int i2)
 {
 		if (p1 > p2 || i1 > i2) return NULL;
 		TreeNode * root = new TreeNode (preorder[p1]);
 		auto pos = find(inorder.begin() + i1, inorder.begin() + i2, preorder[p1]) - inorder.begin() - i1 ;
 		root -> left = build (preorder, p1 + 1, p1 + pos, inorder, i1, pos + i1 - 1);
 		root -> right = build (preorder, p1 + pos + 1, p2, inorder, i1 + pos + 1, i2);
 		return root;
 }
