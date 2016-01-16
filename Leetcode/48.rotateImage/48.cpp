//1 2 3 reverse   7 8 9 swap  7 4 1
//4 5 6 ==>   		4 5 6 ===>	8 5 2
//7 8 9		  	  	1 2 3	  		9 6 3


void rotate(vector<vector<int> > &matrix) 
 {
 	reverse(matrix.begin(), matrix.end());
 	for (int i = 0; i < matrix.size(); ++i)
 		for (j = i + 1; j < matrix.size(); ++j)
 			swap(matrix[i][j], matrix[j][i]);
 }
