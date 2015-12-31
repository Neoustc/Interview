// We use a vector<bool> visited to record all the visited nodes
//  and another vector<bool> onpath to record the visited nodes of the current DFS visit.
//  Once the current visit is finished,
//  we reset the onpath value of the starting node to false.
class Solution {
private:
	vector<unordered_set<int> > graph; 
public:
	vector<unordered_set<int> > make_graph(int numCourses, vector<pair<int, int> > & prerequisites)
	{
		vector<unordered_set<int> > graph(numCourses);
		for (auto i : prerequisites)
			graph[i.second].insert(i.first);
		return graph;
	}
	
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        int m = prerequisites.size();
        vector<bool> visited(numCourses, false);
        vector<bool> onpath(numCourses, false);
        vector<unordered_set<int> > graph = make_graph(numCourses, prerequisites);      
        for (int i = 0; i < numCourses; ++i)
        {
        	if (visited[i])continue;
        	if (!dfs(i, graph, visited, onpath))return false;
        }
        return true;
    }

   bool dfs(int i, vector<unordered_set<int> > & graph, vector<bool>& visited, vector<bool> & onpath)
    {
    	if (visited[i]) return true;
    	visited[i] = true;
        onpath[i] = true;
    	for (auto next : graph[i])
    	{
    	    if (onpath[next]) return false;
    		if (!dfs(next, graph, visited, onpath))return false;
    	}
    	onpath[i] = false;
    	return true;
    }   
};
