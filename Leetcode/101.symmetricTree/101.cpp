  bool isSymmetric(TreeNode* root) 
  {
  	if (!root) return true;
  	else return sysmetric(root -> left, root -> right);
  }
  bool sysmetric(TreeNode * l, TreeNode * r)
  {
  	if (!l && !r) return true;
  	if (!l && r || l && !r) return false;
  	if (l -> val != r -> val) return false;
  	return sysmetric(l -> left, r -> right) && sysmetric(l -> right, r -> left);
  }
