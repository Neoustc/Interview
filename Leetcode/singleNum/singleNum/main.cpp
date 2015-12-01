#include <iostream>
#include <vector>
using namespace std;
//all the num repeat 5 times except one num,find that one 
// write the truth table then you will get the formula;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int a = 0;
    	int b = 0;
    	int c = 0;
    	for (int d : nums)
    	{
    		//cout<<d<<endl;
    		int ta = (~d&a) | (d&b&c);
    		int tb = (~d&b) | (d&(b^c));
    		c = (~d&c) | (d&~a&~c);
    		a = ta;
    		b = tb;
    		//cout<<a << b <<c<<endl;
    	}
    	return a|b|c;//|c|b;
    }
    int singleNumber2(vector<int>& A) {
    int na = 0, nb = 0, nc = 0;
    int n = A.size();
    for(int i = 0; i < n; i++){
        nb = nb ^ (A[i] & na);
        na = (na ^ A[i]) & ~nc;
        nc = nc ^ (A[i] & ~na & ~nb);
    }
    return na & ~nb & ~nc;
}
};
int main(int argc, char const *argv[])
{
	Solution S;
	vector<int> v ={13, 13, 4,4,4 ,13, 13, 13, 2, 2, 2, 2, 2};
	cout<<S.singleNumber(v);
	return 0;
}
