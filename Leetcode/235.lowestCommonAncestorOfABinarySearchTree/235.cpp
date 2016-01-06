 TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
 {
 	if ( (p -> val - root -> val) * (q -> val - root -> val) > 0)
 		{
 			if (p -> val < root -> val)
 				lowestCommonAncestor( root ->left, p, q);
 			else
 				lowestCommonAncestor( root ->right, p, q);
 		}
    else return root;
 }
