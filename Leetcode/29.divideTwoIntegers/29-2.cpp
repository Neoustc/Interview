int divide(int dividend, int divisor) 
 {
 	if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    if (dividend == INT_MIN)
    {
    	if (divisor == -1) return INT_MAX;
    	else if (divisor == 1) return dividend;
    	else return ((divisor & 1) == 1) ? divide (dividend + 1, divisor) : divide (dividend >> 1, divisor >> 1);
    }
    if (divisor == INT_MIN) return 0;
    long d = labs(dividend);
 	long s = labs(divisor);	
 	int res = 0;
    while (d >= s)
 	{
 		long temp = s, multiple = 1;
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
