//https://leetcode.com/discuss/54438/4-7-lines-recursive-iterative-ruby-c-java-python
int closestValue(TreeNode* root, double target) 
 {
 	int closest = root -> val;
 	while (root)
 	{
 		if (abs (closest - target) >= abs (root -> val - target))
 			closest = root -> val;
 		root = target < root -> val ? root -> left : root -> right;
 	}
 	return closest;
 }
