 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int> level;
        vector<vector<int> > res;
        if (!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        bool cnLevel = 0;
        while(!que.empty())
        {
        	int size = que.size();
        	for (int i = 0; i < size; ++i)
        	{
        	TreeNode* tmp = que.front();
        	level.push_back(tmp -> val);
        	if (tmp -> left) que.push(tmp -> left);
        	if (tmp -> right) que.push(tmp -> right);
        	que.pop();
        	}
        	if (cnLevel == 1)
        		reverse(level.begin(), level.end());
        	res.push_back(level);
        	level.clear();
        	cnLevel ^= 1;
        }
        return res;
    }
