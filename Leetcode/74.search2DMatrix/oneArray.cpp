//n * m matrix convert to an array => matrix[x][y] => a[x * m + y]
//an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
// three reason: it's not a good idea:
// 1. m *n might overflow;
// 2. use expensive operations such as / and %;
// 3. Cache hit rate. This method is not as cache friendly as doing the row , column 
// 2 binary search way.

 bool searchMatrix(vector<vector<int> >& matrix, int target)
 {
 	int n = matrix.size();
 	int m = matrix[0].size();
 	int l = 0, r = m * n - 1;
 	while (l != r){
 		int mid = (l + r - 1) >> 1;
 		if (matrix[mid / m][mid % m] < target)
 			l = mid + 1;
 		else 
 			r = mid;
 	}
 	return matrix[r / m][r % m] == target;
 }
