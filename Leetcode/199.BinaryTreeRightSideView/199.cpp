 // push the last element in each level to the result. BFS
  vector<int> rightSideView(TreeNode* root) {
        vector<int> right;
        if (!root) return right;
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        while (!toVisit.empty()) {
            TreeNode* rightNode = toVisit.back();
            right.push_back(rightNode -> val);
            int num = toVisit.size();
            for (int i = 0; i < num; i++) {
                TreeNode* node = toVisit.front();
                toVisit.pop();
                if (node -> left) toVisit.push(node -> left);
                if (node -> right) toVisit.push(node -> right);
            }
        }
        return right;
    }
