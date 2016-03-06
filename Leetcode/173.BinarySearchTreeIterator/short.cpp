/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private :
    stack<TreeNode*> stk;    
public:
    BSTIterator(TreeNode *root) {
        if (!root) return;
        TreeNode *cur = root;
        while (cur || !stk.empty())
        {
            while (cur)
            {
                stk.push(cur);
                cur = cur -> left;
            }
            break;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * cur = stk.top();
        stk.pop();
        int res =  cur -> val;
        cur = cur -> right;
        while (cur)
        {
            stk.push(cur);
            cur = cur -> left;
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
