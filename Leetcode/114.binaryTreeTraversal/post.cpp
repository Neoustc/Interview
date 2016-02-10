 vector<int> postorderTraversal(TreeNode* root) 
 {
	vector<int> res;
 	if (!root) return res;
 	stack<TreeNode*> stk;
 	TreeNode * cur = root;
 	TreeNode * previsited = NULL;
 	while (cur || !stk.empty())
 	{
 		while (cur)
 		{
 			stk.push(cur);
 			cur = cur -> left;
 		}
 		cur = stk.top();
 		//if the right child is not null or haven't been visited;
 		if (cur -> right && previsited != cur -> right)
 				cur = cur -> right;
 		else{
 				res.push_back(cur -> val);
 				previsited = cur;
 				stk.pop();
 				cur = NULL;
 		}
 	}
 	return res;
 }
