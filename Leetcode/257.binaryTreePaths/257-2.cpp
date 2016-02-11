vector<string> binaryTreePaths(TreeNode* root) 
 {
 	vector<string> res;
 	TreeNode *cur;
 	string s = "";
 	dfs(root, res, s);
 	return res;
 }

 void dfs(TreeNode * root, vector<string> & res, string s)
 {
 	if (!root) return;
 	else s += to_string(root -> val);
 	if (!root -> left && !root -> right)	
 		{
 			res.push_back(s);
 			return;
 		}
 	dfs (root -> left, res, s + "->");
 	dfs (root -> right, res, s + "->");
 	return;
 }
