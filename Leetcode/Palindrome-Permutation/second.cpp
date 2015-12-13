Problem Description:

Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].

Hint:

If a palindromic permutation exists, we just need to generate the first half of the string.
To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.
——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
 //http://www.cnblogs.com/jcliBlogger/p/4752065.html
 #include <iostream>
#include <vector>
#include <string>
using namespace std;
 class Solution {
  public:
     vector<string> generatePalindromes(string s) {
     vector<string> res;
    // unordered_map<char, int> counter;
     int count[256] = {0};
     int odd = 0; 
     char mid; 
     string half;
     for (char c : s)
    		odd += ++count[c] & 1 ? 1 : -1;
     if(odd >= 2) return res;
     for (int i = 0; i < 256; i++)
     {
     	if(count[i] & 1)
     		mid = char(i);
     		half += string(count[i] / 2, char(i));
     }
     helper (res, half, mid, 0);
     return res;
     }
     void helper (vector<string> & res, string s, char mid, int begin)
     {
     	if (begin >= s.size())
     	{
     	string t = s;
     	reverse(t.begin(), t.end());
     	t += mid;
     	t += s;
     	res.push_back(t); 
     	return ; 
     	}

     	for (int i = begin; i < s.size(); ++i)
     	{
     		if (i == begin || s[i] != s[i - 1])
     			{
     			swap(s[i], s[begin]);
     			helper(res, s, mid, begin + 1);
     			}
     	}

     }
 };
 int main(int argc, char const *argv[])
 {
 	Solution s;
 	string x = "abcccba";
 	vector<string> v = s.generatePalindromes(x);
 	for (std::vector<string>::iterator i = v.begin(); i != v.end(); ++i)
 	{
 		cout<< *i <<endl;
 	}
 	return 0;
 }
    
