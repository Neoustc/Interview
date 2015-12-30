//http://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle/
 //k ==> Number of floors
 //n ==> Number of Eggs
//Minimum number of trials in worst case
// eggDrop(n, k) : minimum number of trials needed to find the critical floor in worst case
// eggDrop(n, k) = 1 + min{ max(eggDrop(n - 1, x - 1), eggDrop(n, k -x)) : x in {1,2...K} };
// (First formula: means the egg is broken in this trial, so we have n - 1 eggs, and the critical
// 	floor must under  the x - 1 floor.
// second formula : means we success this time , the egg is good ,we still have n eggs , and we can 
// sure that the critical floor in the above floor ,which num is K - x;
#include <iostream>
#include <vector>
using namespace std;
int eggDrop(int n, int k)
{
	//boundary case
	vector<vector<int> > dp(n + 1, vector<int>(k + 1, INT_MAX));
	int time = INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		dp[i][1] = 1;
		dp[i][0] = 0;
	}
	for (int j = 1; j <= k; ++j)
		dp[1][j] = j;

	for(int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= k; ++j)
			for (int x = 1; x <= j; x++)
			{
				time = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
				dp[i][j] = min(time, dp[i][j]);
			}
	}
	return dp[n][k];
}
int main()
{
	//int n = 3, k = 14;
	cout<<eggDrop(2, 36
		);
}
