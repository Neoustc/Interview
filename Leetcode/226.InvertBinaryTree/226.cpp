class Solution {
public:
	//recursive
     TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return NULL;
    root -> left= invertTree(root -> left);
		root -> right = invertTree(root -> right);
		swap(root -> right, root->left);
		return root;
    }
     // iterative
     // The iterative solution is basically a level order traversal. push all the nodes of the same level to a queue or stack
     //then swap their left subtree and right subtree and iterate over their subtrees
     
     TreeNode* invertTree(TreeNode* root) {
     	if (root == NULL) return NULL;
     	stack<TreeNode *> stk;
     	stk.push(root);
     	while (!stk.empty())
     	{
     		TreeNode * t = stk.top();
     		swap(t -> left, t -> right);
     		stk.pop();
     		if (t -> left)
     		stk.push(t -> left);
     		if (t -> right)
     		stk.push(t -> right);
     	}
     	return root;
     }
     //queue
     TreeNode* invertTree(TreeNode* root) {
     if (root == NULL) return NULL;
     	queue<TreeNode *> q;
     	q.push(root);
     	while (!q.empty())
     	{
     		TreeNode * t = q.front();
     		swap(t -> left, t -> right);
     		q.pop();
     		if (t -> left)
     		q.push(t -> left);
     		if (t -> right)
     		q.push(t -> right);
     	}
     	return root;
     }
};	
