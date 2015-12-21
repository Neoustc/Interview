//for newton method  you can approach the result from 1.0 or X-self;

	int mySqrt_Newton(int x)
	{
		long r = x;
		while(r * r > x)
			r = (r + x / r) / 2;
		return r;
	}    

def sqrt(self, x):
	i = 1.0;
	while(true):
		j = (i + x / i) /2;
		if(abs(i - j) < 0.0000005):
			break;
		i = j;
	return int(j);
