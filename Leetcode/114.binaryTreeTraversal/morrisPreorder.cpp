//http://blog.csdn.net/u010738052/article/details/50649605
vector<int> preorderTraversal(TreeNode* root)
{
	TreeNode * cur = root, *predecessor = NULL;
	vector<int> res;
	while (cur)
	{
		if (cur -> left)
		{
			predecessor = cur -> left;
			while (predecessor -> right && predecessor ->right != cur)
				predecessor = predecessor -> right;
			if (!predecessor -> right)
			{
				res.push_back(cur -> val);
				predecessor -> right = cur;
				cur = cur -> left;
			}
			else {
				predecessor -> right = NULL;
				cur = cur -> right;
			}
		}
		else {
			res.push_back(cur -> val);
			cur = cur -> right;
		}
	}
	return res;
}
*************************************

vector<int> preorderTraversal(TreeNode* root)
{
    TreeNode * cur = root, *predecessor = NULL;
    vector<int> res;
    while (cur)
    {
        if (!cur -> left)
        {
            res.push_back(cur -> val);
            cur = cur -> right;
        }
        else{
            predecessor = cur -> left;
            while (predecessor -> right && predecessor -> right != cur)
                predecessor = predecessor -> right;
            if (!predecessor -> right)
            {
                res.push_back(cur -> val); // difference with inorder, push the value when index is build;
                predecessor -> right = cur;
                cur = cur -> left;
            }
            else{
                predecessor -> right = NULL;
                cur = cur -> right;
            }
        }
    }
    return res;
}
