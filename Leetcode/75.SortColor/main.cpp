//slow version another method is counting sort;
// 8ms
void sortColors(vector<int>& nums) {
    	int n = num.size();
    	int i = -1, j = -1, k = -1;
    	for (int x = 0; x < n; ++x)
    	{
    		if (nums[x] == 0)
    		{
    			nums[++k] = 2;
    			nums[++j] = 1; 
    			nums[++i] = 0;	
    		}
    		else if (nums[x] == 1)
    		{
    			nums[++k] = 2;
    			nums[++j] = 1;
    		}
    		else nums[++k] = 2;
    	}
     }
