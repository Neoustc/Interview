// BFS
// The vertices of the graph are simply the position of the first characters of 
//the words and each edge reprsents a word;
// the question is simply check if there is a path from 0 - s.size();
bool wordBreak(string s, unordered_set<string> &dict) 
{
	queue<int> que;
	unordered_set <int> visited;
	que.push(0);
	while (!que.empty())
	{
		int start = que.front();
		que.pop();
		if (visited.find(start) == visited.end())
		{
			visited.insert(start);
			for (int j = start; j < s.size(); ++j)
			{
				string word(s, start, j - start + 1);
				if (dict.find(word) != dict.end())
				{
					que.push(j + 1);
					if (j + 1 == s.size())
						return true;
				}
			}
		}
	}
	return false;
}
