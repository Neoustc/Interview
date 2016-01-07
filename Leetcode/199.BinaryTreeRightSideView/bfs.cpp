 vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> que;
    vector<int> res;
    if (!root) return res;
    que.push(root);
    while (!que.empty())
    {
        TreeNode *t = que.front();
        res.push_back(t -> val);
        int size = que.size();
        for (int i = 0; i < size; ++i)
        {
        TreeNode *t = que.front();
        if (t -> right) que.push(t -> right);
        if (t -> left) que.push(t -> left);
        que.pop();
        }
    }
    return res;
    }
