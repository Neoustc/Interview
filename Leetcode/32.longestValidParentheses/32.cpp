//longest[i] longest substring ends i;
// if (s[i] == '(')  longest[i] = 0;
// if (s[i] == ')')
// 	//if (s[i - 1] == '(') longest[i] = longest[i - 2] + 2;
// 	if (s[i - 1] == ')' && s[i - longest[i - 1] - 1] =='(') 
// 		longest[i] = longest[i - 1] + 2 + longest[i - longest[i - 1] - 2]   
int longestValidParentheses(string s) {
	int n = s.size(), curMax = 0;
	vector<int> longest(n + 1, 0);
	for (int i = 1; i < n; ++i)
	{
		if (s[i] == ')' && i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '(')
		{
			longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0);
			curMax = max (longest[i], curMax);
		}

	}

    }

     int longestValidParentheses(string s) {
        int n = s.size(), curMax = 0;
        int dp[n + 1] = {0}; //dp[i] ...end[i - 1];
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == ')')
            {
                int  left = i - dp[i] - 1;
                if (left >= 0 && s[left] == '(')
                    dp[i + 1] = dp[i] + dp[left] + 2;
                curMax = max(curMax, dp[i + 1]);
            }
        }
        return curMax;
    }

int longestValidParentheses(string s) {
       int len = s.size(), maxL=0, i;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < len; ++i)
        {
        	if (s[i] == ')' && stk.top() >= 0 && s[stk.top()] == '(')
        	{
        		stk.pop();
        		maxL = max(maxL, i - stk.top());
        	}
        	else 
        		stk.push(i);
        }
        return maxL;
    }


