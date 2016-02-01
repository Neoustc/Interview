class Solution {
public:
  bool isAdditiveNumber(string num)
{
	for (int i = 1; i <= num.size() / 2; ++i)
		for (int j = 1; j <= (num.size() - i) / 2; ++j)
			if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j))) 
				return true;
			return false;
}

bool check(string num1, string num2, string num)
{
	if (num1.size() > 1 && num1[0] == '0' || num2.size() > 1 && num2[0] == '0') return false;
	string sum = add(num1, num2);
	if (num == sum) return true;
	if (num.size() <= sum.size() || sum.compare(num.substr(0, sum.size())) != 0) return false; 
	else return check(num2, sum, num.substr(sum.size()));
}

string add(string& s1, string& s2)
{
	int carry = 0;
	string res = "";
	int n1 = s1.size(), n2 = s2.size();
	while (n1 || n2 || carry) 
	{
		carry += (n1 > 0 ? s1[--n1] - '0' : 0);
		carry += (n2 > 0 ? s2[--n2] - '0' : 0);
		res = to_string(carry % 10) + res;
		carry /= 10;
	}
	return res;
}

};
