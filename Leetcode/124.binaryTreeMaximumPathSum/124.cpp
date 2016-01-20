class Solution {
public:
int sum;
    int maxPathSum(TreeNode* root) {
        sum = INT_MIN;
        pathSum(root);
        return sum;
    }
int pathSum (TreeNode *node)
{
	if (!node) return 0;
	int left = max (0, pathSum(node -> left));
	int right = max (0, pathSum(node -> right));
	sum = max (sum, left + right + node -> val);
	return max(left, right) + node -> val;
}
