class Solution {
public:
  vector<string> removeInvalidParentheses(string s) 
 	{
 		vector<string> res;
 		queue<string> que;
 		unordered_set <string> st;
 		bool found = false;
  		que.push(s);
  		st.insert(s);
 		while (!que.empty()) {
 			string tmp = que.front();
 			que.pop();
 			//because the two level string size will only differ 1,
 			//so if this level has valid string that must be even num size, so the next level won't have valid one.
 			if (isvalid(tmp)) 
 			 	{
 			 	    found = true;
 			 		res.push_back(tmp);
 			    }
 				if(!found){
     				int tsize = tmp.size();
     				for (int i = 0; i < tsize; ++i)
     				{
     				   // if (!isalpha(tmp[i])){
     					 if (tmp[i] == '(' || tmp[i] == ')') {
     					string t = tmp.substr(0, i) + tmp.substr(i + 1);
     				  if(st.find(t) == st.end())
     					{
     						st.insert(t);
     						que.push(t);
     					}
     				    }
     				}
 				}
 			}
 		return res;
 	}
 	bool isvalid (string& s){
        int count = 0;
       for (char c : s){
 		if (c == '(') count ++;
 		else if (c == ')'&& !count--) return false;
 		}
        return count == 0;
 	}
};
