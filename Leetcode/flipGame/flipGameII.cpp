Problem Description:
ref :
https://leetcode.com/discuss/64344/ 
http://www.cnblogs.com/jcliBlogger/p/4886741.html
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.

____________________________________________________________________________________________________________________________

 Suppose originally the board of size N contains only '+' signs, then roughly we have:

T(N) = T(N-2) + T(N-3) + [T(2) + T(N-4)] + [T(3) + T(N-5)] + ... 
        [T(N-5) + T(3)] + [T(N-4) + T(2)] + T(N-3) + T(N-2)
     = 2 * sum(T[i])  (i = 3..N-2)
 T(N) = 2^(N-1) 

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	 bool canWin(string s) {
	 	int n = s.size();               
	 	for (int i = 0; i < n - 1; ++i)
	 	{
	 		if (s[i] == '+' && s[i + 1] == '+')
	 		{
	 			s[i] = s[i + 1] = '-';
	 			bool wins = !canWin(s);
	 			s[i] = s[i + 1] = '+';
	 			if (wins) return true;
	 		}
	 	}
	 	return false;
	 }
};
	int main(int argc, char const *argv[])
	{
		Solution S;
		cout<< S.canWin("++--+++");
		return 0;
	}
