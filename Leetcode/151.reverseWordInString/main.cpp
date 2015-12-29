//http://blog.csdn.net/u010738052/article/details/50431975

class Solution {
public:
    void reverseWords(string& s) {
   		trim(s);//remove the whitespace and reverse.
   		int l = 0;
   		for (int i = 0; i < s.size(); ++i)
   		{
   			if (s[i] == ' ')
   			{
   				reverse(s.begin() + l, s.begin() + i);
   				l = i + 1;
   			}
   		}
   		reverse(s.begin() + l, s.end());// we need one more operation to reverse the last word. 
   		return;
    }

    void trim (string& s)
    {
    int i;
    int n = s.size();
    for (i = n - 1; i >= 0 && s[i] == ' '; --i){}
    s = s.substr(0, i + 1);
    reverse(begin(s), end(s));
    for (i = s.size() - 1; i >= 0 && s[i] == ' '; --i){}
    s = s.substr(0, i + 1);
    n = s.size();
    int tail = 0;
    for (i = 0; i < n;)
    {	
    	if (s[i] != ' ' || (s[i] == ' ' && s[i - 1] != ' '))
    		s[tail++] = s[i];
    	i++;
    }
    s = s.substr(0, tail);// remove the traling spaces
    return ;
}
};
