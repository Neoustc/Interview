//http://blog.csdn.net/u010738052/article/details/50531051
 vector<int> spiralOrder(vector<vector<int>>& matrix) 
  {

    int m = matrix.size();
    int n = m ? matrix[0].size() : 0;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> res;
  // vector<vector<int> > dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int steps[2] = {n, m - 1};//steps can work
    int iDir = 0;           //index of direction
    int ir = 0, ic = -1;  // initial position
    while (steps[iDir % 2]) 
    {
        for (int i = 0; i < steps[iDir % 2]; ++i)
        {
            ir += dirs[iDir][0];
            ic += dirs[iDir][1];
            res.push_back(matrix[ir][ic]);
        }
        steps[iDir % 2]--;
        iDir = (iDir + 1) % 4;
    }
    return res;
  }
