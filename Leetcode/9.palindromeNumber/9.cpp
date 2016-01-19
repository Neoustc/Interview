 maintain two divisors to get the most and least significant digits
 and compare them.
 class Solution {
public:
   bool isPalindrome (int x) 
 {
 	//if (x < 0) return false;
 	//if ( 0 <= x &&  x < 10) return true;
 	//if (x < 0 || (x && !(x % 10))) return false; check whether the num is negative or could divide by 10, like 10, 190...
 	int p = 0;
 	int q = x;
 	while (q > 0)
 	{
 		p = p * 10 + q % 10;
 		q = q / 10;
 	}
 	return x == p;
 	//cout << p <<" " << q <<endl;
 	//if (x == p) return true;
 	//return false;
 }
};
