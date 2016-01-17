string convertToTitle(int n) 
{
	string res;
	while (n > 0)
	{
		char c = ((n - 1) % 26) + 'A';
		res = c + res;
		n = (n - 1) / 26; //Z
	}
    return res;
}
