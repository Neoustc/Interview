class Solution {
public:
 //test case : 1122, 2211;
  string getHint(string secret, string guess) 
{
	int n = secret.size();
	unordered_map<char, int> mps;
	unordered_map<char, int> mpg;
	int bulls = 0, cows = 0;
	for (auto i = 0; i < n; ++i)
		{
		if (secret[i] == guess[i]) 
				bulls++;
		else{
		mps[secret[i]]++;
		mpg[guess[i]]++;
		}
	}
	for (auto p : mps)
	{
		if (p.second && mpg[p.first] > 0)
		cows += min(p.second , mpg[p.first]);	
	}
	return to_string(bulls) + "A" + to_string(cows) + "B";
}
};
