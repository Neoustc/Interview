// The recursion basic idea is:
// public int countNodes(TreeNode root) {
//     if (root == null)
//         return 0;
// return 1 + countNodes(root.left) + countNodes(root.right) 
// O(n) solution
// but this is a complete tree, so we walk all the right and left to determine the 
// height and whether it is a full tree. if so, the number is 2^height - 1;
// Since always at least one of the two recursive calls is a full tree;
// at leat one of two calls immediately stops.
// O((logn)^2).T(n) = T(n / 2) + log(n);

int countNodes(TreeNode* root) 
{
	if (!root) return 0;
	int height = 0;
	TreeNode* left = root, *right = root;
	while (right != NULL)
	{
		height++;
		left = left -> left;
		right = right -> right;	
	}
	if (!left) return (1 << height) - 1;
 	return 1 + countNodes(root -> left) + countNodes(root -> right);
}

********************
 int height(TreeNode root) {
        return root == null ? -1 : 1 + height(root.left);
 }
int countNodes(TreeNode * root)
{
	int nodes = 0, h = height(root);
	while (root != null)
	{
		if (height(root -> right) == h - 1)//full
		{
			nodes += 1 << h;
			root = root -> right;
		}
		else {						// complete
			nodes += 1 << h - 1;
			root = root -> left;
		}
		h --;
	}
	return nodes;
}




