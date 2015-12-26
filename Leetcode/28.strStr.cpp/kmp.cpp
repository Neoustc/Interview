//KMP
//http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
   int strStr(string haystack, string needle) {
        int m=haystack.size(),n=needle.size();
    	if(!n)return 0;
    	vector<int> lps=kmpProcess(needle);
    	for (int i = 0; i < n; ++i)
    	{
    		cout<<lps[i]<<" ";
    	}
    	for (int i = 0,j=0; i<m;)
    	{
    		if(haystack[i]==needle[j]){
    			i++;
    			j++;
    		}
    		if(j==n)return i-j;
    		if(i<m&&haystack[i]!=needle[j])
    			{
    				if(j)j=lps[j-1];
    				else i++;
    			}
    		
    	}
    	return -1;
}
vector<int> kmpProcess(string & needle)
{
	int n=needle.size();
	std::vector<int> lps(n,0);//lonest proper prefix or suffix
	for (int i = 1,len=0; i <n;)
	{
		if(needle[i]==needle[len])// keep track of the length of the longest prefix suffix value
			{
				len++;//len : length of the previous longest prefix suffix
				lps[i]=len;
				i++;
			}
			else if(len==0)
			{
				lps[i]=0;
				i++;
			}
			else {
				len=lps[len-1];
             //This is tricky. Consider the example "ababe......ababc", i is index of 'c', len==4. The longest prefix suffix is "abab",
             //when pat[i]!=pat[len], we get new prefix "ababe" and suffix "ababc", which are not equal. 
             //This means we can't increment length of lps based on current lps "abab" with len==4. We may want to increment it based on
             //the longest prefix suffix with length < len==4, which by definition is lps of "abab". So we set len to lps[len-1],
             //which is 2, now the lps is "ab". Then check pat[i]==pat[len] again due to the while loop, which is also the reason
             //why we do not increment i here. The iteration of i terminate until len==0 (didn't find lps ends with pat[i]) or found
             //a lps ends with pat[i].
			}
	}
	return lps;
}
};
int main(int argc, char const *argv[])
    {
    	Solution A;
    	cout<<A.strStr("aaaaaaaaaa","aaaaaa");//0,0,1,0
    	return 0;
    
}
