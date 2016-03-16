class Solution {
	int stringHash(const string & s)
		{
			int res = 0;
			for (int i = 0; i < s.size(); ++i)
				res = (s[i] + 31 * res ) % 997;
			return res;
		}
	int exponential (int n)
	{
		int p = 1;
		for (int i = 0; i < n; ++i)
			p = (p * 31) % 997;
		return p;
	}

	public :
	vector<int> findSubstring(string S, vector<string> &L) 
    {
    	vector<int> result;

    	int cntL = L.size();
    	int lenL = L[0].size();
    	int lenS = S.length();

    	if ((cntL == 0) || (lenS == 0) || (lenS < cntL * lenL))
    		return result;
    	// computer hash for L
    	int hashSum = 0;
    	unordered_set <int> strSet;
    	//[] empty bracket means the the body of lambda expression accesses no variables in the
    	//enclosing scope.
    	// [&] means all variables that you refer to are captured by reference, 
    	// and [=] means they are captured by value. You can use a default capture mode, 
    	// and then specify the opposite mode explicitly for specific variables.
//4 same methods: access total by ref, factor by value; 
// [&total, factor]
// [factor, &total]
// [&, factor]
// [factor, &]
// [=, &total]
// [&total, =]
    	for_each (L.begin(), L.end(), [&](const string & s)
    	{
    		int hs = stringHash(s);
    		strSet.insert(hs);
    		hashSum += hs;
    	});
    	int power = exponential(lenL - 1);

    	// computer hash for each position (using rabin-karp) O(lenS)
    	vector<int> hashes;
    	hashes.push_back(stringHash(S.substr(0, lenL)));
    	//(BASE * (HASH1 - FIRST VALUE + MOD (if < 0)) + NEW VALUE ) % MOD
    	for(int i = 1; i <= lenS - lenL; ++i)
    	{
    		int newHash = (31 * (hashes.back() - power * S[i - 1] % 997 + 997) + S[i + lenL - 1]) % 997;
    		hashes.push_back(newHash);
    	}
	 // if substring S[i..i+len) is not in L, set hashes[i] to 0, O(n)
    	// lenS- lenL = hashes.size();
    	for (int i = 0; i < hashes.size(); ++i)
    	{
    		if (!strSet.count(hashes[i]))
    			hashes[i] = 0;
    	}
        
    	vector<int> preVHsum(lenL, 0);
    	for (int j = 0; j <= min(lenL - 1, lenS - cntL * lenL); ++j)
    	{
    		int curHsum = 0;
    		for (int k = 0; k <= cntL - 1; k++)
    		{
    			curHsum += hashes[j + k * lenL];
    			if (curHsum == hashSum)
    			   {
    			       result.push_back(j);
    			   }
    		}
    		preVHsum[j] = curHsum;
    	}

    	for (int i = 1; i <= (lenS - cntL * lenL) / lenL; ++i)
    	{
    		for (int j = 0; j <= min(lenL - 1, lenS - (i + cntL) * lenL); ++j)
    		{
    			int curHsum = preVHsum[j] - hashes[(i - 1) * lenL + j] + hashes[(i - 1 + cntL) * lenL + j];
    			if (curHsum == hashSum)
    				result.push_back(i * lenL + j);
    			preVHsum[j] = curHsum;
    		}
    	
    	}
    	return result;
    }
    
};
