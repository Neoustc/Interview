Best Meeting Point
ref:http://www.cnblogs.com/jcliBlogger/p/4901473.html
//The geometric median of a discrete set of sample points 
//in a Euclidean space is the point minimizing the sum of distances 
//to the sample points.

 //the median minimizes the sum of absolute deviations. 
class Solution {
public:
    int minTotalDistance(vector<vector<int> >& grid) 
    {
    	int m = grid.size(), n = grid[0].size();
    	vector<int>  x, y;
    	for (int i = 0; i < m; i++)
    		for (int j = 0; j < n; j++)
    		{
    			if (grid[i][j])
    			{
    				x.push_back(i);
    				y.push_back(j);
    			}

    		}
    	sort(y.begin(), y.end());
    	int c = x.size();
    	int path = 0;
    	int xmedian = x[c / 2];
    	int ymedian = y[c / 2];
    	for (int i : x) path += abs(i - xmedian);
    	for (int j : y) path += abs(j - ymedian);
    	return path;
    }
    };
