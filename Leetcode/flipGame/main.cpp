You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

For example, given s = "++++", after one move, it may become one of the following states:

[
  "--++",
  "+--+",
  "++--"
]
If there is no valid move, return an empty list [].
_______________________________________________________________________________________________________________________________
/*
traverse the string find the consecutive '+' convert to the'-' then push to the result ,remember to revert the string
*/

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
    	int n = s.size();
    	vector<string> res;
    	for (int i = 0; i < s.size(); ++i)
    	{
    		if (s[i] == s[i + 1] && s[i] == '+')
    		{
    			s[i + 1] = s[i] = '-';
    			res.push_back(s);
    			s[i + 1] = s[i] = '+';
    		}
    	}
    	return res;
    }
};
