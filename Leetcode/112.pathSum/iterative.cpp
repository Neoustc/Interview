  bool hasPathSum(TreeNode* root, int sum) {
{
 	 if (!root) return false;
 	 stack<pair<TreeNode *, int> > stk;
 	 stk.push(make_pair(root, sum));
 	 while (!stk.empty())
 	 {
 	 	pair<TreeNode *, int> pr = stk.top();
 	 	stk.pop();
 	 	TreeNode * node = pr.first;
 	 	int remain = pr.second;
 	 	if (! (node -> left) && !(node -> right) && remain == node -> val)
 	 		return true;
 	 	if (node -> left)
 	 		stk.push(make_pair(node -> left, remain - node -> val));
 	 	if (node -> right)
 	 		stk.push(make_pair(node -> right, remain - node -> val));
 	 }
 	 return false;
  }
