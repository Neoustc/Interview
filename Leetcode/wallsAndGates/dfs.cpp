http://www.cnblogs.com/jcliBlogger/p/4836567.html

class Solution {
 public:
     void wallsAndGates(vector<vector<int> >& rooms) {
     	// int m = rooms.size();
     	// int n = rooms[0].size();
     	int m = rooms.size(), n = m ? rooms[0].size() : 0;
     	for (int i = 0; i < m; i++)
     		for (int j = 0; j < n; j++)
     			if (rooms[i][j] == 0)
     				walk(rooms, i, j, m, n, 0);
     }
     void walk(vector<vector<int> > & rooms, int i, int j, int m, int n, int step)
     {
     	if(j + 1 < n && rooms[i][j + 1] > step + 1)// pruning the branch...
     		{
     			rooms[i][j + 1] = min(step + 1, rooms[i][j + 1]);
     			walk(rooms, i, j + 1, m, n, roos[i][j + 1]);
     		}
     	if(j - 1 >= 0 && rooms[i][j - 1] > step + 1)
     		{
     			rooms[i][j - 1] = step + 1;
     			walk(rooms, i, j - 1, m, n, roos[i][j - 1]);
     		}
     	if(i - 1 >= 0 && rooms[i - 1][j] > step + 1)
     		{
     			rooms[i - 1][j] = step + 1;
     			walk(rooms, i - 1, j, m, n, roos[i - 1][j]);
     		}
     	if(i + 1 < m && rooms[i + 1][j] > step + 1)
     		{
     			rooms[i + 1][j] = step + 1;
     			walk(rooms, i + 1, j, m, n, rooms[i + 1][j]);
     		}






     }
}
