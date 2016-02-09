 vector<int> preorderTraversal(TreeNode* root) 
 {
 	vector<int> res;
 	if (!root) return res;
 	stack<TreeNode*> stk;
 	TreeNode * cur = root;
 	while (!stk.empty() || cur)
 	{
 		if (cur)
 		{
 			stk.push(cur);
 			res.push_back(cur -> val);
 			cur = cur -> left;
 		}
 		else{
 			cur = stk.top();
 			stk.pop();
 			cur = cur ->right;
 		}
 	}
 	return res;
 }
