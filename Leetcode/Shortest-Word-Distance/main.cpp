Shortest Word Distance
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = "coding", word2 = "practice", return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
_____________________________________________________________________________________________________________________________
//http://www.cnblogs.com/jcliBlogger/p/4704962.html
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
  public:
     int shortestDistance(vector<string>& words, string word1, string word2) 
     {
     	int n = words.size();
     	int i = -n, j = -n, dist = INT_MAX;
     	for (int x = 0; x < n; x++)
     	{
     		if (words[x] == word1)
     			{
     				i = x;
     				//dist = min(dist, abs(i - j));			
				}
     		if (words[x] == word2)
     			{
     				j = x;
     			//	
     			}
     			dist = min(dist, abs(i - j));	
     	}
     	return dist;
     }
 };
int main(int argc, char const *argv[])
{
	vector<string> v{"abc", "aa" , "bc", "abc", "aa"};
	Solution s;
	cout<<s.shortestDistance(v, "abc","aa");
	return 0;
}
