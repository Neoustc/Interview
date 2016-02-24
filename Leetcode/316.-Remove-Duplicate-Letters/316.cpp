 // count the occurrency for each char;
//traverse the char of string s, decrease the count of current char;
//if the char is in the result, just skip the char, else if the char is smaller than 
//the last char of the string, and the last char of string's count is still more than 1 time 
// we could push the current char and pop out the last char of the result. 
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
