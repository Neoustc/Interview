class Solution {
public:
   int calculate(string s) 
{
    int n = s.size();
	stack<int> signs;
	int sign = 1;
	int num = 0;
	int sum = 0;
	signs.push(sign);
	for (int i = 0; i < n; ++i)
 	{
		if (isdigit(s[i]))
 		{
 			num = num * 10 + s[i] - '0';
 		}
 		else {
 			if (s[i] == '+')
 			{
 				sum += sign * signs.top() * num;
 				sign = 1;
 				num = 0;
 			}
 			else if (s[i] == '-')
 			{
 				sum += sign * signs.top() * num;
 				sign = -1;
 				num = 0;
 			}
 			else if (s[i] == '(')
 			{
 				sign = signs.top() * sign;
 				signs.push(sign);
 				sign = 1;
 			}
 			else if (s[i] == ')')
 			{
 				sum += sign * signs.top() * num;
 				signs.pop();
 				num = 0;
 			}
 		}
	}
	sum += signs.top() * sign * num;
	return sum;
}
};
