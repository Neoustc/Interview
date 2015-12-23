//http://blog.csdn.net/u010738052/article/details/50384695
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       	int n = nums.size();
    	if (n <= 2) return n;
    	int j = 0, flag = 0;
    	for (int i = 1; i < n; ++i)
    	{
    		if (nums[i] == nums[j] && flag == 0)
    		{
    			flag = 1;
    			nums[++j] = nums[i];
    		}
    		else if (nums[i] != nums[j])
    		{
    			nums[++j] = nums[i];
    			flag = 0;
    		}
    	}
    	return j + 1;
    }
};
************************************************
A common way :

int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int pos = 1;
        for (int i = 2; i < nums.size(); i++)
            if (nums[i] != nums[pos] || nums[i] != nums[pos - 1])
                nums[++pos] = nums[i];
        return pos + 1;
    }
