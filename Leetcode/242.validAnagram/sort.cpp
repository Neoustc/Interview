   bool isAnagram(string s, string t) { 
    sort((char*)s.c_str(), (char*)s.c_str() + s.size());
    sort((char*)t.c_str(), (char*)t.c_str() + t.size());
    return s == t; 
