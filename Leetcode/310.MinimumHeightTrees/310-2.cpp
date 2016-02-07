vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
{
     if (n == 1) return {0};
      vector<unordered_set<int> > graph(n);
        for (auto e : edges){
        	graph[e.first].insert(e.second);
        	graph[e.second].insert(e.first);
        }

    vector<int> leaves;
    for (int i = 0; i < n; ++i)
    	if (graph[i].size() == 1)
    			leaves.push_back(i);
    while(true){
    	vector<int> newLeaves;
    	for (int i : leaves)
    	{
    		for (auto j : graph[i]){ // must use for loop otherwisr will cause runtime error
    		graph[j].erase(i);
    		if (graph[j].size() == 1) newLeaves.push_back(j);
    		}
    	}
    	if(newLeaves.empty())
    	{
    	    return leaves;
    	}
    	leaves = newLeaves;
    }
}
};
