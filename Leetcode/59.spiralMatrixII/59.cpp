class Solution {
public:
   vector<vector<int> > generateMatrix(int n) 
 {
 	int r1 = 0, r2 = n - 1, c1 = 0, c2 = n - 1;
 	int num = 1;
 	vector<vector<int> > res(n, vector<int>(n));
 	while (true)
 	{
 		for (int col = c1; col <= c2; col++) res[r1][col] = num++;
 		if (++r1 > r2) break;

 		for (int row = r1; row <= r2; row++) res[row][c2] = num++;
 		if (--c2 < c1) break;

 		for (int col = c2; col >= c1; col--) res[r2][col] = num++;
 		if (--r2 < r1) break;

 		for (int row = r2; row >= r1; row--) res[row][c1] = num++;
 		if (c1++ > c2) break;
 	}
 	return res;

 }
};
