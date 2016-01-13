vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,multiset<string> > mp;
        int n=strs.size();
        vector<vector<string> >res;
        for(auto s:strs)
        {
        	string t=s;
        	t=sortstr(s);//sort() works too
        	mp[t].insert(s);
        }
        for(auto m:mp)
        {
        	vector<string> v(m.second.begin(),m.second.end());
        	res.push_back(v);
        }
        return res;
    }
        string sortstr(string &s)
        {
        	int  count[26]={0};
        	for(int i:s)
        		++count[i-'a'];
        	string t;
        	for(int i=0;i<26;++i)
        	{
        		string tmp(count[i],char('a'+i));
        		t+=tmp;
        	}
        	return t;
        }
};
