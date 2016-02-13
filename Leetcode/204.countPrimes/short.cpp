int countPrimes(int n)
 {
    if (n == 0 || n == 1 || n == 2) return 0;
 	bool* isPrime = new bool[n];
 	memset(isPrime, true, sizeof(bool) *n);
    int count = n - 2 ;
 	for (int i = 2; i * i < n; ++i)
 	{
 		if (!isPrime[i]) continue;
 		for (int j = i * i; j < n; j += i)
 		{
 		    if(isPrime[j])
 		    {
 		    isPrime[j] = false;
 			count --;
 		    }
 		}
 	}
 
//  	for (int i = 2; i < n; ++i)
//  		if (isPrime[i]) count ++;
 	return count;
 }
