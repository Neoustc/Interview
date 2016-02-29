int removeElement(vector<int>& nums, int val) 
{
	int n = nums.size() - 1;
    if (n < 0) return 0;
	int i = 0;
	while (i <= n)
	{
		if (nums[i] != val)
			++i;
		else 
			swap (nums[i], nums[n--]);
	}
	return i == nums.size() || nums[i] == val? i : i + 1;
}

 int removeElement(vector<int>& nums, int val) {
       int last=0,cur=0;
       int n = nums.size();
        while (cur<n)
       {
       	if(nums[cur]!=val)
       	{
       		swap(nums[last++],nums[cur]);
       	}
       	cur++;
       }
       return last;
   }
};
