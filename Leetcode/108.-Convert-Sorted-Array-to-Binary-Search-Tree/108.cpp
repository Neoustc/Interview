  TreeNode* sortedArrayToBST(vector<int>& nums) {
  	int n = nums.size();
  	return convert(nums, 0, n - 1); 
  }

TreeNode * convert(vector<int>& nums, int i, int j)
{
	if (i > j) return NULL;
	int m = i + ((j - i) >> 1);
	TreeNode * root = new TreeNode (nums[m]);
	root -> left = convert(nums, i, m - 1);
	root -> right = convert(nums, m + 1, j);
	return root;
}
