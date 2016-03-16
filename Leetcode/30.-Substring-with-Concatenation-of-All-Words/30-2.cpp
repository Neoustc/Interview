// space is O (m * wordSize), time is O(n * m);
    vector<int> findSubstring(string s, vector<string>& words) {
        	if(s == "" || !words.size()) return {};
        	int n = s.size(), m = words.size();
        	unordered_map<string, int> mp;
        	vector<int> res;
        	for (auto word : words)
        		mp[word]++;
        	int wordSize = words[0].size();
        	int start = 0, end = 0, count = 0;
        for (; start <= n - m * wordSize; ++start)
        {
        	end = start; count = 0;
        	unordered_map <string, int> mp1;
        	while (end <= n - (m - count) * wordSize) {	
        	string tmp = s.substr(end, wordSize);
        	if (mp.count(tmp))
        		 {
        		 	mp1[tmp]++;
        		 	if (mp1[tmp] > mp[tmp]) break;
        		 	count++;
        		 	if (count == m) res.push_back(start);
        		 }
        	else break;
	        end += wordSize; 
        	}
        }
        return res;
    }
