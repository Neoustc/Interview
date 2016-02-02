//record the information of state transitions directly in the board.
// States:
//  0 : dead to dead
//  1 : live to live
//  2 : live to dead
//  3 : dead to live
*********************
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        int di[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int dj[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (int k = 0; k < 8; k++) {
                    int ii = i + di[k], jj = j + dj[k];
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                    if (board[ii][jj] == 1 || board[ii][jj] == 2) live++;
                }
                if (board[i][j] == 1 && (live < 2 || live > 3)) board[i][j] = 2;
                else if (!board[i][j] && live == 3) board[i][j] = 3;
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] %= 2;
    }
};
