class Solution {
public:
   bool isAdditiveNumber(string num) 
{
	int n = num.size();
	if (n <= 2) return 0;
	for(int size1 = 1; size1 <= n / 2; size1 ++)
	{
		if(size1 > 1 && num[0] == '0') break;
		int start = size1;
		for (int size2 = 1; size1 + size2 <= n - max(size1, size2); size2++)
		{
		    start = size1;
			if(size2 > 1 && num[start] == '0')break;
		    long num1 = stol(num.substr(0, size1));  // num1 
			long num2 = stol(num.substr(start, size2)); // num2
			long num3 = num1 + num2;
			int len = to_string(num3).size();
			int length = size2; //save the current size of num2
			while (start + length + len <= n && stol(num.substr(start + length, len)) == num3)
			{
				if (start + length + len == n) return true;
				start += length;
				num1 = num2;
				num2 = num3;
				length = len;
				num3 = num1 + num2;
				len = to_string(num3).size();
			}
		}
	}
	return false;

}

};
