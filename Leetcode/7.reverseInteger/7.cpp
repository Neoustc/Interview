//consider the overflow
class Solution {
public:
   int reverse(int x) 
{
	if (x == 0) return 0;
	int sign = 1;
	if (x < 0) 	sign = -1;
	x = x * sign;
	int res = 0;
	while (x > 0)
	{
		if (res > INT_MAX / 10 )
			return 0;
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res * sign;
}
};
