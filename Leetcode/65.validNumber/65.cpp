//http://blog.csdn.net/u010738052/article/details/50473683
//1. skip the leading blank space 
//2. check the leading sign and check the number of digits. if there is a dot, A valid num has no more than 1 point and at least one digit 
//3. check if the exponent part is valid. We do this if the significand is followed by ‘e’. Simply skip the leading sign and count the number of digits and can’t have a dot. A valid exponent contain at least one digit. 
//4. skip the trailing white space 
bool isNumber(string s)
{
	int i = 0;
	//skip the whitespaces
	for (; s[i] == ' '; ++i){}
	// check the significand
	// skip the sign if exist
	if (s[i] == '+' || s[i] == '-') ++i;

	int n_nm, n_pt;
	for (n_nm = 0, n_pt = 0; isdigit(s[i]) || s[i] == '.'; ++i)
		s[i] == '.'? n_pt++ : n_nm ++;
	if (n_pt > 1 || n_nm < 1) return false;

	//check the exponent if exist
	if (s[i] == 'e')
	{
		++i;
		if (s[i] == '+' || s[i] == '-') ++i;
		int n_nm = 0;
		for (; isdigit(s[i]); ++i, n_nm++){}
		if (n_nm < 1) return false;
	}
	
	for (; s[i] == ' '; i++){}
	return s[i] == 0;
}
