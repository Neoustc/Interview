void quickSort(std::vector<int >&v,int left,int right){
	if(left<right)
	{
		int pos=partition(v,left,right);
		quickSort(v,left,pos-1);
		quickSort(v,pos+1,right);
	}
}
////////////////////
int partition1(std::vector<int>&nums,int left,int right)
{
int pivot=nums[left];
int l=left+1,r=right;
while(l<=r){
	if(nums[l]>pivot&&nums[r]<pivot)
	swap(nums[l++],nums[r--]);
	if(nums[l]<=pivot)l++;
	if(nums[r]>=pivot)r--;
}
swap(nums[left],nums[r]);
  return r;
}
/////////////////
int partition2(std::vector<int> &nums,int left,int right) // descending order
	{
		int pivot=nums[right];
		int l=left-1;
		for(int r=left;r<=right-1;r++)
		{
			if(nums[r]>=pivot)
			swap(nums[++l],nums[r]);
		}
		swap(nums[++l],nums[right]);
		return l;
	}
};
