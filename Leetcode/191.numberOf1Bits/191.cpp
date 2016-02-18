  int hammingWeight(uint32_t n) 
  {
  	int res = 0;
  	while (n) {
  		n &= n - 1;
  		res++;
  	}
  	return res;
  }

  int hammingWeight(uint32_t n) 
  {
  	int count = 0;
  	for (int i = 0; i < 32; ++i)
  	{
  		count += (n >> i & 1) ? 1 : 0;
  	}
  	return count;
  }
