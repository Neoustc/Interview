//http://blog.csdn.net/u010738052/article/details/50400903
class Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string> res;
    	if(n==0)return res;
    	string s;
    	combine(res,s,n,0);
    	return res;
 }
 void combine(std::vector<string>& res,string s,int left,int right)
 {
 		if(left==0&&right==0)
 		{
 			res.push_back(s);
 			return;
 		}
 		if(left>0)
 			combine(res,s+'(',left-1,right+1);
 		if(right>0)
 			combine(res,s+')',left,right-1);
 }
};
