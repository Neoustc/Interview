 unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
 UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
 	if (!node) return NULL;
 	UndirectedGraphNode * copy = new UndirectedGraphNode(node -> label);
 	mp[node] = copy;
 	queue<UndirectedGraphNode* > toVisit;
 	toVisit.push(node);
 	while(!toVisit.empty()){
 	UndirectedGraphNode * cur = toVisit.front();
 	toVisit.pop();
 	for (auto nei : cur -> neighbors)
 	{
 		 if (mp.find(nei) == mp.end()) {
         UndirectedGraphNode* nei_copy = new UndirectedGraphNode(nei -> label);
         mp[nei] = nei_copy;
         toVisit.push(nei);//all push to the queue
     	}
     	mp[cur] -> neighbors.push_back(mp[nei]); //already visited
 	}
 	}
 	return copy;
 }
