class Solution {
public:
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
 	vector<bool> visited(numCourses, false);
 	vector<bool> onpath(numCourses, false);
 	for (int i = 0; i < numCourses; ++i)
 	{
 		if (visited[i]) continue;
 		if (!dfs(numCourses, graph, visited, onpath, res, i)) return {};
 	}
 	reverse(res.begin(), res.end());
 	return res;
 }

 bool dfs(int numCourses, vector<unordered_set<int> >& graph, vector<bool> & visited, vector<bool> & onpath, vector<int> & res, int start)
 {
 	//if (onpath[start]) return false;
 	if (visited[start]) return  true;
 	visited[start] = onpath[start] = true;
 	for (auto neigh : graph[start])
 	{
 		if (onpath[neigh]) return false;
 		if (!dfs(numCourses, graph, visited, onpath, res, neigh)) return false;
 	}
 	onpath[start] = false;
 	res.push_back(start);
 	return true;
 }

};
