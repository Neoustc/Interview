//http://www.cnblogs.com/jcliBlogger/p/4836567.html
void wallsAndGates(vector<vector<int>>& rooms) 
{
	int m = rooms.size(), n = m ? rooms[0].size() : 0;//nice
	queue<pair<int, int> >q;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if(!rooms[i][j])
				q.push({i, j});
	for (int d = 1; q.size(); ++d) {//nice
		for (int k = q.size(); k--;){
			int i = q.front().first;
			int j = q.front().second;
			q.pop();
			#define add(in, i, j) if (in && rooms[i][j] > d){ //nice #define 
			q.push({i, j});
			rooms[i][j] = d;
		}
			add(i, i - 1, j);
			add(i + 1 < m, i + 1, j);
			add(j, i, j - 1);
			add(j + 1 < n, i, j + 1);
			#undef add
		}
	}



}
