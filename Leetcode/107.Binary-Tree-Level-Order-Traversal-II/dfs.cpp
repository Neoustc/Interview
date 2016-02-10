 vector< vector<int> > levelOrderBottom(TreeNode* root) 
 {
 	vector < vector<int> > res;
 	if (!root) return res;
    vector <int> v;
    dfs (root, res, 0);
    return vector<vector<int> > (res.rbegin(), res.rend());
 }

 void dfs(TreeNode * root, vector<vector<int> >& res, int level)
 {
 	if (!root) return;
 	if (res.size() == level)
 	{
 		vector<int> v;
 		res.push_back(v);
 	}
 	res[level].push_back(root -> val);
 	dfs(root -> left, res, level + 1);
 	dfs(root -> right, res, level + 1);
 	return;
 }
