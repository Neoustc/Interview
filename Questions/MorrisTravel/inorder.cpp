//http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
// use the leaf node's extra empty left and right pointers, find the predecessor and successor 
// space complexity is O(1)
//time complexity is O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
    	TreeNode * prev = NULL, TreeNode * cur = root;
    	std::vector<int > res;
    	while(cur){
    		if(cur -> left == NULL) {
    			res.push_back(cur -> val);
    			cur = cur -> right;
    		}
    		else{
    			pre = cur -> left;
    		while(pre -> right && pre ->right != cur) //find the predecessor   		
    			pre = pre ->right; 
    		if(pre -> right == NULL)
    		{
    			pre -> right = cur;
    			cur = cur ->left;
    		}
    		else{
    			pre->right = NULL;
    			res.push_back(cur -> val);
    			cur = cur ->right;
    		}
    	}
	}
