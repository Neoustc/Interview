 int calculate(string s) {
 	int n = s.size();
 	stack<int> stk; //store the previous sum and sign
 	int sign = 1;
 	int num = 0;
 	int sum = 0;
 	for (int i = 0; i < n; ++i)
 	{
 		if (isdigit(s[i]))
 		{
 			num = num * 10 + (s[i] - '0');
 		}
 		else{
 			if (s[i] == '-' || s[i] == '+')
 			{
 				sum += sign * num;
 				sign = s[i] == '-' ? -1 : 1;
 				num = 0;
 			}
 			else if (s[i] == '(')
 			{
 				stk.push(sum);
 				stk.push(sign);
 				sum = 0;
 				sign = 1;
 			}
 			else if (s[i] == ')')
 			{
 			    sum += sign * num;
 				sign = stk.top();
 				stk.pop();
 				sum = stk.top() + sign * sum;
 				stk.pop();
 				sign = 1;
 				num = 0;
 			}
 		}
 	}
 	sum += sign * num;//don't forget this sum at last for axample:    2 - 1
 	return sum;
 }
};
