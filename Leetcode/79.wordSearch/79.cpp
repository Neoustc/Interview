class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) 
 {
 	int m = board.size();
 	int n = m ? board[0].size() : 0;
    vector<vector<bool> > visited (m, vector<bool> (n, false));
 	for (int i = 0; i < m; ++i)
 		for (int j = 0; j < n; ++j)
 		{
 			if (board[i][j] == word[0] && helper(board, visited, word, i, j, 0))
 				 return true;
 		}
 		return false;
 }
 bool helper (vector<vector<char> > & board, vector<vector<bool> > & visited, string& word, int i, int j, int start)
 {
 	visited[i][j] = true;
 	if (start == word.size() - 1)
 		return true;
 	if (i - 1 >= 0  && !visited[i - 1][j] && board[i - 1][j] == word[start + 1])
 		 if (helper(board, visited, word, i - 1, j, start + 1))
 		 	return true;
 	if (i + 1 < board.size() && !visited[i + 1][j] && board[i + 1][j] == word[start + 1])
 		 if (helper(board, visited, word, i + 1, j, start + 1))
 		 	return true;
 	if (j - 1 >= 0  && !visited[i][j - 1] && board[i][j - 1] == word[start + 1])
 		 if (helper(board, visited, word, i, j - 1, start + 1))
 		 	return true;
 	if (j + 1 < board[0].size() && !visited[i][j + 1] && board[i][j + 1] == word[start + 1])
 		 if (helper(board, visited, word, i, j + 1, start + 1))
 		 	return true;
 	visited[i][j] = false;
 	return false;
 }
};
