vector<int> inorderTraversal(TreeNode* root)
{
    TreeNode * cur = root, *predecessor = NULL;
    vector<int> res;
    while (cur)
    {
        if (!cur -> left)//left most node
        {
            res.push_back(cur -> val);
            cur = cur -> right;
        }
        else{         //check and add index for each step;
            predecessor = cur -> left; 
            while (predecessor -> right && predecessor -> right != cur)
                predecessor = predecessor -> right;
            if (!predecessor -> right) // connected the predecessor with cur.(index)
            {
                predecessor -> right = cur;
                cur = cur -> left;
            }
            else{
                predecessor -> right = NULL; //disable the index.
                res.push_back(cur -> val);
                cur = cur -> right;
            }

        }
    }
    return res;
}
