  string convert(string s, int numRows) 
  {
  	int n = s.size();
  	string * strs = new string[numRows];
  	int step = numRows;
  	int dir = 1;
  	int pos = 0;
  	for (int i = 0; i < n; ++i)
  	{	
  		int j = 0;
  		if (i < n && dir && j < step)
  		{
  			while (i < n && j < step)
  			{
	  			strs[pos++] = s[i];
	  			j++;
  			}
  			if (i == n) break;
  			else { dir = 0; step = numRows - 1; pos --;}
  		}
  		else if (i < n && !dir && j < step)
  		{
  			while (i < n && j < step)
  			{
  				j++;
  				strs[--pos] = s[i];
  				
  			}
  			if (i == n) break;
  			else {dir = 1; pos ++}
  		}
  	}
  	string res;
  	for (int i = 0; i < numRows; ++i)
  		res += strs[i];
  	delete[] strs;
  	return res;
  }
