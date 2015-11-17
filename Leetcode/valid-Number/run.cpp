/*
1.skip the whitespace of the front
2.skip the sign ,count the num of digit and points,
no more than one point and at least one digit
3.for exponent,skip the leading sign and count the number of digits
at least one digit 
4.skip the traling whitespace and reach the '\0';

The program shouldn't use just one For loop  to judge,
otherwise you will use lots of flag and the exit of procedure 
is complex,so we just follow the sequence of the significand of the  numeric

space+sign+num+point+e+sign+num+space;//AT LEAST ONE DIGIT
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
		bool isNumber(string s){
			int i=0,n=s.size();
			//skip the whitespace ;
			for(;s[i]==' ';i++){}
			// 
			if(s[i]=='+'||s[i]=='-')
				i++;
			int num=0,npoint=0;
			for(;(s[i]<='9'&& s[i]>='0')||s[i]=='.';i++)//isdigit()
				s[i]=='.' ? npoint++ : num++;
			if(npoint>1||num<1)
				{	
					//cout<<npoint<<num;
					return 0;
				}
			if(s[i]=='e'){
				i++;
				if (s[i]=='+'||s[i]=='-')i++;
				num=0;
				for(;s[i]>='0'&&s[i]<='9';i++,num++)
				{}
				if(num<1)return 0;
			}
			for (;s[i]==' ';i++){}
			return s[i]=='\0';//i==n

		}
	};
int main(int argc, char const *argv[])
{
	Solution A;
	cout<<A.isNumber("");
	return 0;
}
