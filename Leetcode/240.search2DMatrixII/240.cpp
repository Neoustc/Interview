//search from the top - right element and reduce the range for further searching by comparisons
//between target and the current element. 
class Solution {
public:
   bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
	int n = m ? matrix[0].size() : 0;
	int i = 0, j = n - 1;
	while (i < m && j >= 0)
	{
		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] > target)
			 j--;
		else i++;
	}
	return false;
   }
};
