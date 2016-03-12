  vector<unordered_set<int> > make_graph(int numCourses, vector<pair<int, int> > & prerequisites )
 {
 	vector<unordered_set<int> > graph(numCourses);
 	for (auto pre : prerequisites)
 		graph[pre.second].insert(pre.first);
 	return graph;
 }

 vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) 
 {
 	vector<int> res;
 	vector<unordered_set<int> > graph;
 	graph = make_graph(numCourses, prerequisites);
 	vector<int> visited(numCourses, 0);   //0 unvisited, 1 being visited, 2 visited;
 	for (int i = 0; i < numCourses; ++i)
 	{
 		if (visited[i] == 2) continue;
 		if (!dfs(graph, visited, res, i)) return {};
 	}
 	reverse(res.begin(), res.end());
 	return res;
 }

 bool dfs(vector<unordered_set<int> >& graph, vector<int> & visited, vector<int> & res, int start)
 {
    visited[start] = 1;
    for (auto nei : graph[start])
        {
            if(visited[nei] == 1) return false;
            if (visited[nei] == 2) continue;
            if(!dfs(graph, visited, res, nei)) return false;
        }
    res.push_back(start);
    visited[start] = 2;
    return true;
 }
