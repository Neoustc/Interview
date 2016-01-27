  //http://www.cnblogs.com/jcliBlogger/p/4768875.html
//RLE : running length Algo
  string encode(vector<string>& strs) {
       string res;
       for (string str : strs)
       	res += to_string(str.size()) + '$' + str; 
       return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vectro<string> res;
        int n = s.size(), p = 0;
        while (p < n)
        {
        	size_t pos = s.find('$', p);
        	if (pos == string :: npos) break;
        	size_t sz = stoi(s.substr(p, pos - p));//num
        	res.push_back(s.substr(pos + 1, sz));
        	p = pos + sz + 1;
        }
        return res;
    }
