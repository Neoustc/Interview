class Solution {
public:
     //O(26 *n)
//     removing all letters to the left of s[i],
// removing all s[i]'s from s.
   string removeDuplicateLetters(string s) {
        if (s.length() == 0) return "";
        int *cnt = new int [26]();
        int pos = 0;// the position of the current smallest  char;
        for (int i = 0; i < s.length(); ++i)
            cnt[s[i] - 'a']++;
        for (int i = 0; i < s.length(); ++i)
            {
            if (s[i] < s[pos]) pos = i;
            if (--cnt[s[i] - 'a'] == 0) break;
            }
        //cout<<s[pos]<<endl;
        char res = (s[pos]);
        string tmp = s.substr(pos + 1);
        int p = 0;
        while ( ( p = tmp.find(s[pos])) != string :: npos)
            tmp.replace(p, 1, "");
        //      cout<<"tmp: "<<tmp <<endl;
        //      cout<<"res: "<< res<<endl;
        return res + removeDuplicateLetters(tmp);
    }
};
