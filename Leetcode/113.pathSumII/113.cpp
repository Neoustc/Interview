 vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int > > res;
        if(!root) return res;
        path.push_back(root -> val);
        findpath(root, path, res, sum - root -> val);
    	return res;
    }

    void findpath(TreeNode * root, vector<int> & path, vector<vector<int > > & res, int sum)
    {
    	if (sum == 0 && !root -> left && !root -> right)
    	{
    		res.push_back(path);
    		return;
    	}
    	if (root -> left )
    	{
    		path.push_back(root->left->val);
    		findpath(root->left, path, res, sum - root -> left ->val);
    		path.pop_back();
    	}
    	if (root -> right)
    	{
    		path.push_back(root->right->val);
    		findpath(root->right, path, res, sum - root ->right -> val);
    		path.pop_back();
    	}

    }
