 vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<string> res;
        if(root==NULL) return res ;
        string s=to_string(root->val);
        helper(root,res,s);
        return res;
    }
    void helper(TreeNode* root,std::vector<string>& res,string s)
    {
    	if(!root->left&&!root->right)
    	{
    		res.push_back(s);
    		return;
    	}
    	if(root->left)
    		helper(root->left,res,s+"->"+to_string(root->left->val));
    	if(root->right)
    		helper(root->right,res,s+"->"+to_string(root->right->val));
    }
