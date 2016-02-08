Given a binary tree where all the right nodes are either leaf nodes with a sibling
(a left node that shares the same parent node) or empty, 
flip it upside down and turn it into a tree
 where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},

    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].

   4
  / \
 5   2
    / \
   3   1  
______________________________
TreeNode* upsideDownBinaryTree(TreeNode* root) 
{
	return upsideDown(root, NULL, NULL);
}
TreeNode * upsideDown(TreeNode * root, TreeNode * parent, TreeNode * sibling)
{
	if (!root) return parent;
	TreeNode* left = root -> left;//old left
	TreeNode* right = root -> right;//old right
	root -> left = sibling;//new left child is old right sibling
	root -> right = parent;
	return upsideDown(left, root, right);

}

TreeNode* upsideDownBinaryTree(TreeNode* root) 
{
	TreeNode *r = root;
	TreeNode *parent = NULL;
	TreeNode *sibling = NULL;
	while (r)
	{
		TreeNode *left = r -> left;
		TreeNode *right = r -> right;
		r -> left = sibling;
		r -> right = parent;
		parent = r;
		r = left;
		sibling = right;
	}
}










