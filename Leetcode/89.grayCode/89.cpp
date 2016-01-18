0   n = 0
___
0
1   n = 1
___
00  n = 2
01
11
10
___
000  n = 3
001
011
010
110
111
101
100
class Solution {
public:
       vector<int> grayCode(int n) 
 {
 	vector<int> res(1);
 	for (int i = 0; i < n; ++i)
 	{
 		int s = res.size();
 		for (int j = s - 1; j >= 0; j--)
 		{
 			res.push_back(res[j] + (1 << i));

 		}	
 	}
 	return res;
 }
};
