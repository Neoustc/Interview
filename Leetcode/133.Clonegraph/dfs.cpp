class Solution {
public:
  unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
 UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
 	if (!node) return NULL;
 	if (mp.find(node) == mp.end()){
 	mp[node] = new UndirectedGraphNode(node -> label);
 	for (auto nei : node->neighbors)
 	(mp[node]-> neighbors).push_back(cloneGraph(nei));
 }
 	return mp[node];
 }
};
