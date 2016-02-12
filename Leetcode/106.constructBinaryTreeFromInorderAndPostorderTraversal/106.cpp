 TreeNode *buildTree(vector<int> & in, vector<int> &post) 
{
	int m = in.size(), n = post.size();
 	return build (in, 0, m - 1, post, 0, n - 1);
}

TreeNode * build (vector<int>& in, int i1, int i2, vector<int>& post, int p1, int p2)
{
	if (p1 > p2 || i1 > i2) return NULL;
 	TreeNode * root = new TreeNode (post[p2]);
 	int pos = find(in.begin() + i1, in.begin() + i2, post[p2]) - in.begin() - i1;
 	root -> left = build(in, i1, i1 + pos - 1, post, p1, p1 + pos - 1);
 	root -> right = build(in, i1 + pos + 1, i2, post, p1 + pos, p2 - 1);
 	return root;
}
