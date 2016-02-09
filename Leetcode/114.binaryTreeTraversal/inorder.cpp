 vector<int> inorderTraversal(TreeNode* root) 
 {
 	vector<int> res;
 	if (!root) return res;
 	stack<TreeNode*> stk;
 	TreeNode * cur = root;
 	while (cur || !stk.empty())
 	{
 		if (cur)
 		{
 			stk.push(cur);
 			cur = cur -> left;
 		}
 		else {
 			cur = stk.top();
 			res.push_back(cur -> val);
 			stk.pop();
 			cur = cur -> right;
 		}
 	}
 	return res;
 }
