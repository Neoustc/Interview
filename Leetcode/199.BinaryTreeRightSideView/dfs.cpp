// it's kind of modified Preorder traverse. push root then push root -> right, root -> left.
// when level == res.size(), push the current node into vector, current node must be the rightmost of current level 
vector<int> rightSideView(TreeNode* root)
{
	vector<int> res;
	if (!root) return res;
	dfs(root, res, 0);
	return res;
}

void dfs(TreeNode * root, vector<int> & res, int level)
{
	if (!root) return;
	if (level == res.size())  // key is here.
		res.push_back(root -> val);
	dfs (root -> right, res, level + 1);
	dfs (root -> left, res, level + 1);
}
