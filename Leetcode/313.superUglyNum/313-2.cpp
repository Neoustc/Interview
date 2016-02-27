//o(kn)
 int nthSuperUglyNumber(int n, vector<int>& primes) 
 {
 	int k = primes.size();
 	int *uglyNum = new int[n]();
 	uglyNum[0] = 1;
 	int *index = new int[k]();
 	for (int i = 1 ; i < n; ++i)
 	{
 	    int num = INT_MAX;
 		for (int j = 0; j < k; ++j)
 			num = min (primes[j] * uglyNum[index[j]], num);
 		for (int j = 0; j < k; ++j)
 			if (num % primes[j] == 0) 
 				index[j]++;
 		uglyNum[i] = num; 
 	}
 	return uglyNum[n - 1];
 }
