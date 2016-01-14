 int shortestDistance(vector<string>& words, string word1, string word2) 
     {
     	int n = words.size();
     	int i = - n, j = - n, dist = INT_MAX;
     	for (int x = 0; x < n; x++)
     	{
     		if (words[x] == word1)
     			{
     				i = x;
     				//dist = min(dist, abs(i - j));			
				}
     		if (words[x] == word2)
     			{
     				j = x;
     			//	
     			}
     			dist = min(dist, abs(i - j));	
     	}
     	return dist;
     }
