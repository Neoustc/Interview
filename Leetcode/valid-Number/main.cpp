// https://leetcode.com/problems/valid-number/
class Solution {
// test case :0054047e+6, 0e, e9, 12e1.2, +.8, .,  ,+2e8.0,
runtime  8ms.
// 1. skip the leading wsp;
// 2. check the leading sign;then count the amount of digit
// 3. if it's is a point,check the is there exponent sign ahead;
// 4. if it's exponent,check the previous digit count and next char is a sign or not
// 3. skip the trailing white spaces till the end	

public:
		bool isNumber(string s){
		int i = 0, n = s.size(), pflag = 0, eflag = 0, count = 0;
		for(; s[i]==' ' && i < n; i++){}
		if(i >=n )return false;
		if(s[i] == '-' || s[i] == '+')i++;
		if(i >= n) return false;
		for(; i < n; i++)
		{
			if(isdigit(s[i])) { count++; continue; }
			else if(s[i] == '.'){
				if(pflag == 0 && eflag == 0) pflag = 1;
				else return false;
			}
			else if( s[i] == 'e'){
				if(eflag == 0 && count > 0) { 
				    eflag = 1, count = 0;
				     if( s[i+1] == '-' || s[i+1] == '+')
				     i++;
    			}
				else return false;
			}
			else if(s[i] ==' '){
				for(; s[i] == ' ' && i < n; i++){}
					if(i >= n) break;
				    else return false;
			}
			else return false;
		}
		return (count > 0 ? true : false);
		}
	};
