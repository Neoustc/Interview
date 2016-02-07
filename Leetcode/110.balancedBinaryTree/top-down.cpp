 //O(nlogn)
 bool isBalanced(TreeNode* root) 
 {
 	if (!root) return 1;
 	int left = depth(root -> left);
 	int right = depth(root -> right);
 	if (abs(left - right) <= 1) return isBalanced(root->left) && isBalanced(root ->right);
 	else return false;
 }
 int depth(TreeNode * root)
 {
 	if (!root) return 0;
 	return max(depth(root -> left), depth(root -> right)) + 1;
 }
