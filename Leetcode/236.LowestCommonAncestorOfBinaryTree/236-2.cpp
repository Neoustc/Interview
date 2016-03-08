//Traverse from the root,
// if one of p or q match the root, then root is LCA.
// else recursive search the left and the right;
// if p or q exists in the left, and the other one exists in the right; then root is LCA
// if l && !r means two key exists in the left and the first visited key is the LCA, so return l;
// else if !l && r return right
//注意findLCA这个function的 return 值代表的意思，这个函数是去找左右子树是否包含p/q,
//  有的话 return他们的lca, 如果只有一个p, 那么 return p。
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	return DFS (root, p, q);
}
 TreeNode * DFS (TreeNode * root, TreeNode * p, TreeNode *q)
 {
 	if (root == p || root == q || root == NULL)
 		return root;
 	TreeNode * l = DFS(root -> left, p, q);
 	TreeNode * r = DFS(root -> right, p, q);
 	if (l && !r) return l;
 	if (!l && r) return r;
 	if (l && r) return root;
 	else return NULL;
 }
