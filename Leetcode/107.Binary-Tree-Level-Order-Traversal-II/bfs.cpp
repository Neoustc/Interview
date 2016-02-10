vector< vector<int> > levelOrderBottom(TreeNode* root) 
 {
 	vector < vector<int> > res;
 	if (!root) return res;
    vector <TreeNode*> que; 
    vector <int> v;
    que.push_back(root);
    int i = 0, last = 0;
    while (last < que.size())
    {
    	int size = que.size();
    	for (; last < size; ++last, ++i)
    	{
    		TreeNode * t = que[i];
    		v.push_back(t -> val);
    		if (t -> left) que.push_back(t -> left);
    		if (t -> right) que.push_back(t -> right);
    	}
    	res.push_back(v);
    	v.clear();
    }
    return vector<vector<int>> (res.rbegin(), res.rend());
 }
