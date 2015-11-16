class Solution {
public:
     vector<vector<int> > combinationSum3(int k, int n) {
	std::vector< vector<int> > res;
    std::vector<int> v;
    combine(k,n,res,v,1); //1 means num value through 1 to 9;
    return res;
    }
    
    void combine(int k, int n, vector< vector<int> >& res, vector<int> & v, int begin)
    {
    	if(n == 0 && k == 0)
    	{
    		res.push_back(v);
    		return;
    	}
    	for(int i = begin; i <= 9 && i <= n; i++)
    	{
    		v.push_back(i);
    		combine(k - 1, n - i, res, v, i + 1);
    		v.pop_back();
    	}
    return;
    }
};

int main(int argc, char const *argv[])
{
	//int a[7]={10,1,2,7,6,1,5};
	//std::vector<int> v(a,a+7);
	Solution A;
	std::vector<std::vector<int> > result;
	result=A.combinationSum3(3,9);
	for (std::vector<vector<int> >::iterator i = result.begin(); i!= result.end(); ++i)
	{
		for (std::vector<int >::iterator iter=(*i).begin(); iter != (*i).end(); ++iter)
		{
			cout<<(*iter);
		}
		cout<<endl;
	}
	return 0;
}
