TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	return dfs (root, p, q);
}
 TreeNode * dfs (TreeNode* root, TreeNode* p, TreeNode* q)
 {
 	if (root == p || root == q || root == NULL)
 		return root;
 	TreeNode *l = dfs(root -> left, p, q);
 	TreeNode *r = dfs(root -> right, p, q);
 	 return !l ? r : !r? l : root;
 	//cout << l-> val << " " <<r -> val<<endl; // when two subnodes are not p or q , the sub routines should return null
 //	if (l && !r) return l;
 	//else if (r && !l) return r;	
 	//else if( r && l) return root;
 	//else return NULL;
 } 
