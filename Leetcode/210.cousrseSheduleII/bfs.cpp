http://blog.csdn.net/u010738052/article/details/50444084
vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<unordered_set<int> > graph = make_graph(numCourses, prerequisites);
        vector<int> degrees(numCourses);
        vector<int> res;
        degrees = compute_degree(numCourses, graph);
        for (int i = 0; i < numCourses; ++i)
        {
        	int j = 0;
        	for (; j < numCourses; ++j)
        	{
        		if (!degrees[j]) {
        			res.push_back(j);
        			break;
        		}
        	}
        	if (j == numCourses) return {};
        	for (auto nei : graph[j])
        		degrees[nei]--;
        }
        return res;
    }
    vector<int> compute_degree(int numCourses, vector<unordered_set<int> > & graph)
    {
    	vector<int> degree(numCourses);
    	for(int i = 0; i < graph.size(); ++i)
    	for (auto nei : graph[i])
    	{
    		degree[nei]++;
    	}
    	return degree;
    }

    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
