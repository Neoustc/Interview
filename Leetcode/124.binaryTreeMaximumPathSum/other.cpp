This is the maximum path sum between two leaf.
int pathSum (TreeNode *node)
{
	if (!node) return 0;
	int leftPath = pathSum(node -> left);
	int rightPath = pathSum(node -> right);
	//leftPath = leftPath; 
	//rightPath = rightPath;
	sum = max(sum, leftPath + rightPath + node ->val);
	return  max(leftPath, rightPath)+ node -> val;
}
