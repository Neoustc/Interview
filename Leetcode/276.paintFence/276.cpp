// There is a fence with n posts, each post can be painted with one of the k colors.

// You have to paint all the posts such that no more than two adjacent fence posts have the same color.

// Return the total number of ways you can paint the fence.

// Note:
// n and k are non-negative integers.
// s[i] means the number of solutions when the color of last two fences (whose indexes are i-1,i-2) are same. 
// d[i] means the number of solutions when the color of last two fences are different.
s[i] = d[i - 1] //s
d[i] = (k-1) * (s[i - 1] + d[i - 1]);// d1 , d2 the last two elements 

int numWays(int n, int k) 
{
	if (n <= 1 || k == 0) return n * k;
	int s = k, d2 = k * (k - 1), d1 = k; 
	for (int i = 2; i < n; ++i)
	{
		s = d2;
		d2 = (k - 1) * (d1 + d2);
		d1 = s;
	}
	return s + d2;
}
