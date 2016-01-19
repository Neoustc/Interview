
class Solution {
public:
  int maxDepth(TreeNode *root)
 {
 	if (!root) return 0;
 	queue<TreeNode*> que;
 	que.push(root);
 	int maxDepth = 0;
 	while (!que.empty())
 	{
 		for (int i = 0, size = que.size(); i < size; ++i)
 		{
 		TreeNode * node = que.front();
 		que.pop();
 		if (node -> left) que.push(node -> left);
 		if (node -> right) que.push(node -> right);
 		}
 		maxDepth ++;
 	} 
 	return maxDepth;
 }
};
