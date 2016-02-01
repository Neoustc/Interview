Problem Description:

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
 After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

***************
static int d[4][2] ={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void wallsAndGates(vector<vector<int>>& rooms) {
      	int m = rooms.size();
      	int n = m ? rooms[0].size() : 0;
      	for (int i = 0; i < m; ++i)
      		for (int j = 0; j < n; ++j)
      			if (rooms[i][j] == 0)
      				walk (rooms, m, n, i, j);
    }
 void walk(vector<vector<int> > & rooms, int m, int n, queue<pair<int,int> >& que, int posx, int posy)
 {
    queue<pair<int, int> > que;
 	que.push(make_pair(posx, posy));
	while(!que.empty())
	{
	pair<int,int> p = que.front();
	x = p.first;
	y = p.second;
	for (int k = 0; k < 4; ++k)
	{
		int i = x + d[k], j = j + d[k];
		if (0 <= i && j < m && 0 <= j && j < n && rooms[i][j] > rooms[x][y] + 1)
		{
		rooms[i][j] = rooms[x][y] + 1;
		que.push(make_pair(i, j));
		}
	}
 }

void wallsAndGates(vector<vector<int>>& rooms) {
      	int m = rooms.size();
      	int n = m ? rooms[0].size() : 0;
      	for (int i = 0; i < m; ++i)
      		for (int j = 0; j < n; ++j)
      			if (rooms[i][j] == 0)
      				walk (rooms, m, n, i, j);
    }

    void dfs(vector<vector<int> > & rooms, int m, int n, int i, int j)
    {
    	for (int k = 0; k < 4; k++){
    		int p = i + d[k], q = j + d[k];
    if (0<= p && p < m && 0<= q && q < n && rooms[p][q] > rooms[i][j] + 1)
    	rooms[p][q] = rooms[i][j] + 1;
    	dfs(rooms, m , n, p ,q);
    	}
    }








