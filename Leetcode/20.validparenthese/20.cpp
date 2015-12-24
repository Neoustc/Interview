class Solution {
public:
    bool isValid(string s) {
    	stack<char> stk;
    	for (int i = 0; i < s.size(); ++i)
    	{
    		switch(s[i]){
    		case '(':
    		case '[':
    		case '{':
    			stk.push(s[i]);
    			break;
    		case ')':
    			if(!stk.empty()&&stk.top()=='(')
    				stk.pop();
    			else return false;
    			break;
    		case ']':
    			if(!stk.empty()&&stk.top()=='[')
    				stk.pop();
    			else return false;
    			break;
    		case '}':
    			if(!stk.empty()&&stk.top()=='{')
    				stk.pop();
    			else return false;
    			break;
    		}
    	}
    if(stk.empty())return true;
    else return false;
    }
};
