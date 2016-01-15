//http://blog.csdn.net/u010738052/article/details/50522315
class WordDistance {
  private:
  	unordered_map<string, vector<int> > wordsPos;
  public:
  	 WordDistance(vector<string> words) 
  	 {
  	 	int n = words.size();
  	 	for (int i = 0; i < n; ++i)
  	 		wordsPos[words[i]].push_back(i);
  	 }
  	 int shortest (string word1, string word2)
  	 {
  	 	vector<int> indexs1 = wordsPos[word1];
  	 	vector<int> indexs2 = wordsPos[word2];
  	 	int m = indexs1.size(), n = indexs2.size();
  	 	int i = 0, j = 0, dist = INT_MAX;
  	 	while (i < m && j < n)
  	 	{
  	 		dist = min (dist, abs(indexs1[i] - indexs2[i]));
  	 		if (indexs1[i] < indexs2[i]) i++;
  	 		else j++;
  	 	}
  	 	return dist;
  	 }
