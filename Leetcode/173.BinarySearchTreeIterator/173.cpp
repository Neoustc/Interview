// we need store the values(left children) in the stack. In the constructor and next, we
 //add the next smallest nodes into the stack, when return the next (pop out a left child,
 // we push the right  child see whether it has left child) 
 // next average is O(1) time 
class BSTIterator {

public:
	stack <TreeNode *> stk;
    BSTIterator(TreeNode *root) {
        if (root == NULL) return;
        stk.push(root);
        TreeNode *p = root;
        while (p -> left)
        {
        	stk.push(p -> left);
        	p = p ->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
    	if (!stk.empty()) return 1;
        else return false;
    }

    /** @return the next smallest number */
    int next() {
   		TreeNode * next = stk.pop();
   		stk.pop();
   		TreeNode * p = next;
   		if (p -> right)
   		{
   			stk.push(p -> right);
   			p = p -> right;
   		while (p -> left)
   		{
   			stk.push(p -> left);
   			p = p -> left;
   		}
   		}
        return next -> val;
    }
};
