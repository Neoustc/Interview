//http://blog.csdn.net/u010738052/article/details/50577172
//http://www.cnblogs.com/jcliBlogger/p/4738788.html
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> neighbors(n);
        for (auto e : edges) {
            neighbors[e.first].push_back(e.second);
            neighbors[e.second].push_back(e.first);
        }
        vector<bool> visited(n, false);
        if (hasCycle(neighbors, 0, -1, visited))
            return false;
        for (bool v : visited)
            if (!v) return false; 
        return true;
    }
private:
    bool hasCycle(vector<vector<int>>& neighbors, int kid, int parent, vector<bool>& visited) {
        if (visited[kid]) return true;
        visited[kid] = true;
        for (auto neigh : neighbors[kid])
            if (neigh != parent && hasCycle(neighbors, neigh, kid, visited))
                return true;
        return false;
    }
};
