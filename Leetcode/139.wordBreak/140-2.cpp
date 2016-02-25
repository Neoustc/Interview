unordered_map<string,vector<string> > m;
    vector<string> combine(string word,std::vector<string> prev)
    {
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }


    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if(m.count(s))return m[s];
        vector<string> result;
        if(wordDict.count(s)){
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i)
        {
            string word=s.substr(i);
            if(wordDict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,wordDict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result;
        return result;
    }
