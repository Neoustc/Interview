 vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
	vector<vector<string> > res;
	if (start == end) return res;
	unordered_set<string> Visited;
	unordered_set<string> cur;
	unordered_map <string, vector<string> > graph;
	graph[start] = vector<string>();
	cur.insert(start);
	bool found = false;
	while (!cur.empty() && found == false) { 
		unordered_set<string> queue;
		for (auto& it : cur) {
			Visited.insert(it);
		}
		for (auto& str : cur) {
			string word = str;
			for (int i = 0; i < word.size(); ++i) {
				char before = word[i];
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					if (ch == before) continue;
					word[i] = ch;
					if (dict.count(word) == 0) continue;
					if (word == end) {
						found = true;
						graph[str].push_back(end);
						continue;
					}
					if (found == true && end != word) continue;
					if (Visited.count(word) == 0) {
						queue.insert(word);
						graph[str].push_back(word);
					}
				}
				word[i] = before;
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
void trace (vector<vector<string> >& res, unordered_map<string, vector<string> >& graph, vector<string> path, string start, string end)
{
	path.push_back(start);
	if (start == end) {
		res.push_back(path);
		return ;
	}
	for (auto i : graph[start])
	{
		trace(res,graph,path,i, end);
	}
	path.pop_back();
}
