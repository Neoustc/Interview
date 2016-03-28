class Solution {
public:
   vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
	vector<vector<string> > res;
	if (start == end) return res;
	unordered_set<string> Visited;
	unordered_set<string> cur;
	unordered_map <string, vector<string> > graph;
	graph[end] = vector<string>();
	cur.insert(start);
	bool found = false;
	while (!cur.empty() && found == false) {
		unordered_set<string> queue;
		for (auto& it : cur) {
			Visited.insert(it);
		}
		for (auto& str : cur) {
			string word = str;
			for (int j = 0; j < str.size(); ++j) {
				char before = word[j];
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					if (ch == before) continue;
					word[j] = ch;
					if (dict.count(word) == 0) continue;
					if (found == true && end != word) continue;
					if (end == word) {
						found = true;
						graph[end].push_back(str);
						continue;
					}
					if (Visited.count(word) == 0) {
						queue.insert(word);
						graph[word].push_back(str);
					}
				}
				word[j] = before;
			}	
		}
		cur = queue;
	}
	if (found == true) {
		vector<string> path;
		trace (res, graph, path, start, end);
	}
	return res;
}

void trace (vector<vector<string> >& res, unordered_map<string, vector<string> >& graph, vector<string> path, string start, string now) {
	path.push_back(now);
	if (now == start) {
		vector<string> ans = path;
		reverse (ans.begin(), ans.end());
		res.push_back(ans);
		path.pop_back();
		return;
	} 
    vector<string> cur = graph[now];
	for (int i = 0; i < cur.size(); ++i) {
		trace(res, graph, path, start, cur[i]);
	}
	path.pop_back();
}
};
