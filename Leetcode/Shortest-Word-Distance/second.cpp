ref:http://www.cnblogs.com/jcliBlogger/p/4705282.html
Problem Description:

This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = "coding”, word2 = "practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
______________________________________________________________________________________________________________________________
class WordDistance {
  private:
  	unordered_map<string, vector<int> > wordsPos;
  public:

    WordDistance(vector<string> words) {
    	int n = words.size();
    	for (int i = 0; i < n; i++)
    		wordsPos[words[i]].push_back(i);
    }
    int shorest(string words1, string words2)
    	{
    		vector<int> indexs1 = wordsPos[words1];
    		vector<int> indexs2 = wordsPos[words2];
    		int m = indexs1.size();
    		int n = indexs2.size();
    		int i = 0, j = 0, dist = INT_MAX;
    		while (i < m && j < n){// should remeber the way that find the min dist
    			dist = min(dist, abs[indexs1[i] - indexs2[j]]);
    			if (indexs1[i] < indexs2[j]) i++;
    			else j++;
    		}
    		return dist;
    	}
    };
