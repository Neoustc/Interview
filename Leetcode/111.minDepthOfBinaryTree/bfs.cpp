int minDepth(TreeNode* root) 
{
	if (root == NULL) return 0;
	int res = 0;
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty())
	{
		res++;
		TreeNode * p;
		for (int i = 0, n = q.size(); i < n; ++i)
		{
			q = q.front();
			q.pop();
			if (!p -> left && ! p -> right) return res;
			if (p -> left) 	q.push(p -> left);
			if (p -> right) q.push(p -> right);
		}
	}
	return res;
}
