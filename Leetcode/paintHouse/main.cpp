//http://www.cnblogs.com/jcliBlogger/p/4729957.html
Problem Description:

There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red;costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
____________________________________________________________________________________________________________________________________
class Solution {
public:
	//r,g,b represent the min cost that if paint r,g,b  in the current house;
	// rr,gg,bb represent the .................in the previous house
    int minCost(vector<vector<int> >& costs) {
        int  n = costs.size();
        if (n == 0) return 0;
        int r = g = b = 0;
        for (int i = 0; i < n; i++)
        {
        	int rr = r, bb = b, gg = g;
        	r = costs[i][0] + min(bb, gg);
        	g = costs[i][1] + min(rr, bb);
        	b = costs[i][2] + min(rr, gg);
        }
        return min (r, min(g, b));

    }
};
