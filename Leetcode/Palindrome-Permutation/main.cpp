Palindrome Permutation
//http://www.cnblogs.com/jcliBlogger/p/4748554.html
//https://leetcode.com/discuss/53180/1-4-lines-python-ruby-c-c-java?show=53180#q53180
Problem Description:

Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
____________________________________________________________________________________________________________________________

class Solution {
 public:
    bool canPermutePalindrome(string s) 
    {
    	int count[256] = {0};
    	int odd;//number of char which  appears odd times
    	for (char c : s)
    		odd += ++count[c] & 1 ? 1 : -1;
    	return odd < 2;

    }
     bool canPermutePalindrome(string s) 
    {
    	bitset<256> b;
    	for (char c : s) b .flip(c);
    		return b.count() < 2;
    }
