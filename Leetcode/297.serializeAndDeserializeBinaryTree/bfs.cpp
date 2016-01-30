class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
        	TreeNode* node = que.front();
        	que.pop();
        	if (node == NULL) 
        	{ res+= '#';
        	   continue; }
        	else res += to_string(node -> val) + '#';
        	que.push(node -> left);
        	que.push(node -> right);
        }
        //cout<<res<<endl;
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	int p = 0;
    	int n = data.size();
    	if (!n) return NULL;
    	int pos, val;
    	pos = data.find('#', p);
        val = stoi(data.substr(p, pos - p));
        p = pos + 1;
        TreeNode * root = new TreeNode(val);
    	queue<TreeNode*> que;
    	que.push(root);
    	while (!que.empty())
        {
        	 TreeNode* t = que.front();
        	 que.pop();
        	 pos = data.find('#', p);
        	// if(pos == string::npos) break;
        	 if (pos != p) 
	        	 {
	        	 val = stoi(data.substr(p, pos - p));
	        	 t -> left = new TreeNode(val);
	        	 que.push(t -> left);
	        	 }
	         p = pos + 1;
        	 pos = data.find('#', p);
        	 //if(pos == string::npos) break;
        	 if (pos != p)
        	 {
            	 val = stoi(data.substr(p, pos - p));
	        	 t -> right = new TreeNode(val);
	        	 que.push(t -> right);
	        }
	         p = pos + 1;
        }
        return root;
    }
};
