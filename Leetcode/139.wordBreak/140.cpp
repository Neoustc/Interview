class Solution {
private:
    unordered_map<string, vector<string> > mp;
public:
    vector<string> combine(string& tmp, vector<string> v)
    {
        vector<string> res;
        for (auto i : v)
        {
            res.push_back(tmp +" " + i);
        }
        return res;
    }
    
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
       // if (mp[s].size() > 0) return mp[s];
        if(mp.count(s)) return mp[s];
        int n =  s.size();
        vector<string> res;
        if (wordDict.count(s))
 		res.push_back(s);
        for (int i = 1; i < n; ++i)
        {
            string tmp = s.substr(0, i);
            if (wordDict.count(tmp) > 0)
            {
                string cur = s.substr(i);
                vector<string> rear = combine(tmp, wordBreak(cur, wordDict));
                res.insert(res.end(), rear.begin(), rear.end());
            }
        //      string word=s.substr(i);
        //     if(wordDict.count(word)){
        //         string rem=s.substr(0,i);
        //         vector<string> prev=combine(word,wordBreak(rem,wordDict));
        //         res.insert(res.end(),prev.begin(), prev.end());
        //     }
        // }
        }
        mp[s] = res;
        return res;
    }
};
