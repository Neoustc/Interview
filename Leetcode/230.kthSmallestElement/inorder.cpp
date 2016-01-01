int kthSmallest(TreeNode* root, int k) {
	return kthSmallest(root, k);
}
int smallest(TreeNode* node , int & k)
{
	if (!node) return - 1;
	int val = smallest(node -> left, k);
	if (!k) return val;
	if (!--k) return node->val;
	return smallest(node -> right, k);
}
