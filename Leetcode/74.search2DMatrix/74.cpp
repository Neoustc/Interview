//Search a 2D Matrix
bool searchMatrix(vector<vector<int> >& matrix, int target) 
 {
 	int m = matrix.size();
 	int n = m ? matrix[0].size() : 0;
 	int l = 0, r = m;
 	int mid = 0;
 	while (l < r - 1)
 	{
 		int mid = l + ((r - l) >> 1);
 		if (matrix[mid][0] > target)
 			r = mid;
 		else if (matrix[mid][0] < target)
 			l = mid;
 		else return true;
 	}
 	int row = l;
 	l = 0; 
 	r = n;
 	while (l < r)
 	{	
 		mid = l + ((r - l) >> 1);
 		if (matrix[row][mid] > target)
 			r = mid;
 		else if (matrix[row][mid] < target)
 			l = mid + 1;
 		else return true;
 	} 
 	return false;
 }
