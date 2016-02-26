int sumNumbers(TreeNode* root) 
{
	return dfs (root, 0);//current level sum with previous level sum;
}

int dfs(TreeNode * root, int val)
{
	if (!root) return 0;//
	if (!root -> left && !root -> right) 
	    return val * 10 + root -> val;
	 return dfs (root -> left, val * 10 + root -> val) + dfs (root -> right, val * 10 + root -> val);
}
