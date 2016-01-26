int closestValue(TreeNode* root, double target) 
 {
 	// if (!root) return INT_MAX;
 	// if (root -> val == target) return root -> val;
 	// int minDiff = root ->val; 
 	// int left = closestValue (root -> left, target);
 	// int right = closestValue (root -> right, target);
 	// if (abs(left - target) < abs(right - target))
 	// 	{
 	// 	if (abs(root -> val - target) < abs(left - target))
 	// 		return root -> val;
 	// 	else return left;
 	// 	}
 	int a = root -> val;
 	auto kid = target < a ? root -> left : root -> right;
 	if (!kid) return a;
 	int b = closestValue(kid, target);
 	return abs(a - target) < abs(b - target) ? a : b;
 }
