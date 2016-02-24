 string removeDuplicateLetters(string s)
  {
  	int n = s.size();
  	int count[26] = {0};
  	for (auto c : s)
  		count[c - 'a']++;
  	string res = "";
  	bool inres[26] = {false};
  	for (char c : s)
  	{
  		count[c - 'a']--;
  		if (inres[c - 'a']) continue;
  		while (!res.empty() && c < res.back() && count[res.back() - 'a'] > 0)
  		{
  			inres[res.back() - 'a'] =false;
  			res.pop_back();
  		}
  		res.push_back(c);
  		inres[c - 'a'] = true;
  	}
  	return res;
  }
