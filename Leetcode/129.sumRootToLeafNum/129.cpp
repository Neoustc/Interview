int sumNumbers(TreeNode * root)
{
	stack <TreeNode *> nodes;
	if (!root) return 0;
	int total = 0;
	int current = 0;
	TreeNode * last = NULL, * cur = root;
	while (cur || !nodes.empty())
	{
		while (cur)
 		{
 		    nodes.push(cur);
 		    current *= 10;
 		    current += cur -> val;
 			cur = cur -> left;
 		}
 		
 		    cur = nodes.top();
 			if (cur -> right && cur -> right != last)
 				cur = cur -> right;
 			else {
 				nodes.pop();
 				last = cur;
 				// only add sum of leaf node
 				if (!cur -> right && !cur -> left)
 					total += current;
 				current /= 10;
 				cur = NULL;
 			}
	}
	return total;
}
