class Solution {
public:
     string convert(string s, int numRows) 
  {
  	int n = s.size();
  	if(numRows <= 1) return s;
  	string * strs = new string[numRows];
  	int step = numRows;
  	int dir = 1;
  	int pos = 0;
  	for (int i = 0; i < n;)
  	{	
  		int j = 0;
  		if (i < n && dir && j < step)
  		{
  			while (i < n && j < step)
  			{
	  			strs[pos++] += s[i];
	  			++i;
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
  				strs[--pos] += s[i];
  				++i;
  				
  			}
  			if (i == n) break;
  			else {dir = 1;pos ++;}
  		}
  	}
  	string res;
  	for (int i = 0; i < numRows; ++i)
  		res += strs[i];
  	delete[] strs;
  	return res;
  }
};
