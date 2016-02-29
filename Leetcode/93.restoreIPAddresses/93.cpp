  vector<string> restoreIpAddresses(string s) 
 {
 	int n = s.size();
 	vector<string> res;
 	string tmp = "";
 	parse(s, res, tmp, 0, 0);
 	return res;
 }

 void parse(string s, vector<string>& res, string  tmp, int start, int dotNum)
 {
 	if (dotNum == 4 && start == s.size())
 	{
 		tmp.pop_back();
 		res.push_back(tmp);
 		return ;
 	}
 	if (dotNum < 4 && start < s.size())
 	{
 		string num = "";
 		for (int j = 0; j < 3 && start + j < s.size(); ++j)
 		{
 			num += s[start + j];
 			if (stoi(num) > 255 || num[0] == '0' && j > 0) continue;
 			else
 			{
 				parse(s, res, tmp + num + ".", start + j + 1, dotNum + 1);
 			}
 		}
 	}
 	return;
 }
