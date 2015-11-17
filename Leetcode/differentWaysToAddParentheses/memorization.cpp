class Solution {
	//it's a top down memorization method
public:
   vector<int> diffWaysToCompute(string input) {
   	unordered_map<string, vector<int> > mp;
   	return computeMap(input, mp);
   }

   vector<int> computeMap(string input, unordered_map<string, vector<int> >& mp){
   	vector<int> res;
   	for (int i = 0; i < input.size(); ++i)
   	{
   		char c = input[i];
   		if (ispunct(c)){
   			vector<int> res1, res2;
   			string str = input.substr(0, i);
   			if(mp[str].size() > 0)
   				res1 = mp[str];
   			else res1 = computeMap(str, mp);
   			str = input.substr(i + 1);
   			if(mp[str].size() > 0)
   				res2 = mp[str];
   			else res2 = computeMap(str, mp);	
   		for (auto n1 : res1)
   			for (auto n2 : res2){
   				if (c == '+')
   					res.push_back(n1 + n2);
   				if (c == '-')
   					res.push_back(n1 - n2);
   				else res.push_back(n1 * n2);
   			}
   		}
   	}
   	if (res.empty())
   		res.push_back(stoi(input));
   	mp[input]=res;
   	return res;	
   }
