//search from the top - right element and reduce the range for further searching by comparisons
//between target and the current element. 
bool searchMatrix(vector<vector<int> >& matrix, int target) 
{
	int m = matrix.size();
	int n = m ? 0 : matrix[0].size();
	int i = 0, j = n;
	while (i <= m && j >= 0)
	{
		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] > target)
			 j--;
		else i ++;
	}
	return true;
}
