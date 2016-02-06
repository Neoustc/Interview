int calculate(string s){
	int n = s.size();
	int num = 0;
	int sum = 0;
	char sign = '+';
	stack<int> stk;
	for (int i = 0; i < n; ++i)
	{ 
	    char c = s[i];
		if (isdigit(c))
		{
			num = num * 10 + (c - '0');
		}
		if (!isdigit(c) && c != ' ' || i == n - 1){
			if (sign == '+' || sign == '-')
			{
				num = (sign == '+' ? num : -num);
				stk.push(num);
			}
			else if (sign == '*')
			{
				int t = stk.top() * num;
				stk.pop();
				stk.push(t);
			}
			else if (sign == '/')
			{
				int t = stk.top() / num;
				stk.pop();
				stk.push(t);
			}
			sign = c;
			num = 0;
		}
	}
		while (!stk.empty())
		{
			sum += stk.top();
			stk.pop();
		}
		return sum;
	}
};
