// the idea is very straightforward;
// use visited matrix to record the visited cell, and store the max length which start from
//that cell; 
// do DFS every cell compare every 4 direction and save the max length to the visited matrix;
// once the cell is been visited, the value in the visited cell won't change and it can be the
//reference for its univisted neighbor;
class Solution {
public:
   int dirs[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int longestIncreasingPath(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        vector<vector<int> >  visited(m, vector<int>(n, 0));
        int len = 0;
        for (int i = 0; i < m; ++i)
        	for (int j = 0; j < n; ++j)
        	{	
        		if (visited[i][j] == 0)
        		{
        			len = max(len, dfs(matrix, visited, m, n, i, j, 0));
        		}
        	}
    return len;
    }

int dfs (vector<vector<int> > & matrix, vector <vector<int> > & visited, int& m, int& n, int i, int j, int len)
{
    if (visited[i][j] > 0)
     return visited[i][j];
    int length = len;
	for (int d = 0; d < 4; ++d)
	{
		int x = i + dirs[d][0];
		int y = j + dirs[d][1];
		if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j])
			 	length = max (length, dfs(matrix, visited, m, n, x, y, len));
	}
	visited[i][j] = length + 1;
	return 	visited[i][j];
}

};
