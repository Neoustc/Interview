class Codec {
public :
 string serialize(TreeNode* root) 
 {
 	string res = "";
 	en_preorder(root, res);
 	//cout<<res<<endl;
 	return res;
 }
 void en_preorder(TreeNode* root,  string & res)
	{
		if (!root) {res += '#'; return;}
		else res += to_string(root -> val) + ' ';
		en_preorder(root -> left, res);
		en_preorder(root -> right, res);
	}

 TreeNode* deserialize(string data) 
	 {
	 	return de_preorder(data);
	 }
	TreeNode* de_preorder(string& data)
	 {
	 	int p = 0, pos1, pos2;
	 	pos2 = data.find('#', p);
	 	pos1 = data.find(' ', p);
	 	if (pos2 == string::npos) return NULL;
	 	if (pos1 == string :: npos || pos2 < pos1) {
	 	    data = data.substr(pos2 + 1);
	 	    return NULL;
	 	}
	 	int val = stoi(data.substr(p, pos1 - p));
	 	TreeNode * root = new TreeNode(val);
	 	data = data.substr(pos1 + 1);
	 	root -> left = de_preorder(data);
	 	root -> right = de_preorder(data);
	 	return root;
	 }
};
