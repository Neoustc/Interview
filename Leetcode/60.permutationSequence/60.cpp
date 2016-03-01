class Solution {
public:
string getPermutation(int n,int k){
		int total = factorial (n);
		string res;
		string ret="";
		if(n==1)return "1";
		for(int i=1;i<=n;i++)
			res=res+to_string(i);

		for(int i=1;i<=n;++i)
		{
			int index=(k-1)/(factorial(n-i));	
			ret =ret+res[index];
			res.erase(res.begin()+index);
			k=k-factorial(n-i)*index;
		}
	return ret;
	}
	int factorial(int n)
	{
	    if(n==0)return 1;
		int sum=1;
		for(int i=1;i<=n;++i)
			sum=sum*i;
		return sum;
	}
};
