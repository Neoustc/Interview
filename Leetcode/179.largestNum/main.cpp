//http://blog.csdn.net/u010738052/article/details/50384152

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int num : nums)
            strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(),
            [](const string &m,const string &n){ return m+n > n+m; });
        if (strs[0] == "0")
            return "0";
        return accumulate(begin(strs), end(strs), string(""));
    }  
};

**********************************************
class Solution {
public:
   string largestNumber(vector<int>& nums) 
    {
    	vector<string> arr;
    	for (auto i : nums)
    		arr.push_back(to_string(i));
    	//sort(begin(arr), end(arr),[](string &s1, string &s2){return s1 + s2 > s2 + s1;});
    	sort(arr.begin(), arr.end(), compare);
    	string res = "";
    	for (auto s : arr)
    		res += s;
    	while(res[0] == '0' && res.length() > 1)//[0,0,0] res: 0,0,0;
    		res.erase(0, 1);
    	return res;
    }
static bool compare(const string& s1, const string & s2) //static function
{
	return s1 + s2 > s2 + s1;
}
};
