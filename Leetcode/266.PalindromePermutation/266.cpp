Problem Description:

Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
*****************
bool canPermutePalindrome(string s)
{
	int odd = 0, counts[256] = {0};
	for (char c : s)
		odd += ++counts[c] & 1 ? 1 : -1;
	return odd <= 1;
}

bool canPermutePalindrome(string s)
{
	bitset<256> b;
	for (char c : s)
		b. flip(c);
	return b.count() < 2;
}
