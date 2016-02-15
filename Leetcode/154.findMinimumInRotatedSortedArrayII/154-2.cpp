class Solution {
public:
    int findMin(vector<int>& nums) {
          int left=0,right=nums.size()-1;
        int mid=0;
        while(left<right)
        {	
        	mid=left+((right-left)>>1);
        	if(nums[mid]>nums[right])//we shold compare with right,
        		left=mid+1;
        	else if(nums[mid]<nums[right])
        		right=mid;
        	else --right; //must move right; consider [1, 3, 3];
        }
        return nums[left];
    }
    
};
