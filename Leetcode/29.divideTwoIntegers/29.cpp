class Solution {
public:
   int divide(int dividend, int divisor) 
 {
 	if (divisor == 0 || dividend == INT_MIN && divisor == -1)
 		return INT_MAX;
 	int res = 0;
 	int sign=((dividend<0)^(divisor<0))?-1:1;
 	long d = labs(dividend);
 	long s = labs(divisor);
 	if (dividend < divisor)
 		return 0 ;
 	if (s == 1) return d;
 	//TLE
//  	while (d >= s)
//  	{
//  		d -= s;
//  		res++;
//  	}
  	while (d >= s)
  	{
  		long  temp = s, multiple = 1;
  		while (d >= (temp << 1))
  		{
  			temp <<= 1;
  			multiple <<= 1;
  		}
  		d -= temp;
  		res += multiple;
  	}
 	return res * sign;
 }
};
