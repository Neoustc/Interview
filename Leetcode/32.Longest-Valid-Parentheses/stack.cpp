int longestValidParentheses(string s) {
	    int len = s.size();
	 	stack<int> stk;
	 	int maxlen = 0;
	 	for (int i = 0; i < len; ++i) {
	 		if (stk.empty() || s[i] == '(') {
	 			stk.push(i);
	 		} else {
	 			if (!stk.empty() && s[stk.top()] == '(') {
	 				stk.pop();
	 				if (stk.empty()) maxlen = max (maxlen, i + 1);
	 				else maxlen = max (maxlen, i - stk.top()); 
	 			}
	 			else stk.push(i);
	 		}
	 	}
	 	return maxlen;
	}
