//http://www.cnblogs.com/jcliBlogger/p/4572682.html
class Solution {
 public:
      TreeNode* upsideDownBinaryTree(TreeNode* root) 
      {
  		TreeNode * p = root;
  		TreeNode * parent = NULL;
  		TreeNode * sibling = NULL;
  		while (p){
  			TreeNode * left = p -> left;
  			TreeNode * right = p -> right;
  			p -> left = sibling;
  			p -> right = parent;
  			parent = p;
  			p = left;
  			sibling = right;
  		}
	 return parent;
      }
//recursive
      TreeNode* upsideDownBinaryTree(TreeNode* root) {
      	return upsideDown(root, NULL, NULL);
       }
       TreeNode * upsideDown(TreeNode * root, TreeNode * parent, TreeNode * sibling)
       {
       	if (!root) return parent;
       	TreeNode * left = root -> left;
       	TreeNode * right = root -> right;
       	root -> left = sibling;
       	root -> right = parent;
       	return upsideDown(left, root, right);
       }

 }
