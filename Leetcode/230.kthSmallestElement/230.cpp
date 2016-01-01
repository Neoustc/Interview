int kthSmallest(TreeNode* root, int k) {
	int num = countNode(root);
	int n = countNode(root->right);
	if (k == num - n)
		return (root -> val);
	if (k < num - n)
		return kthSmallest(root -> left, k);
	else return kthSmallest(root -> right, k - num + n);
}
int countNode (TreeNode * root)
{
	if (root == NULL) return 0;
	return 1 + countNode(root -> left) + countNode(root -> right);
}
