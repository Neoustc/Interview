class Solution {
public:
     int myAtoi(string str) {
 	int n = str.size();
 	int i = 0;
 	for (; i < n && str[i] == ' '; ++i){}
 	if (i == n) return 0;
 	int sign = 1;
 	if (str[i] == '+' || str[i] == '-')
 	sign = (str[i++] == '-' ? -1 : 1);
 	int num = 0;
 	for (; i < n; ++i)
 	{
 		if (isdigit(str[i]))
 		{
 			if (num == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10 || num > INT_MAX / 10)
 				{
 					if (sign == -1) return INT_MIN;
 					else return INT_MAX;
 				}
 			num = num * 10 + str[i] - '0';
 		}
 		else return num * sign;
 	}
 	return num * sign;
 }
};
