int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int mid=0;
        while(left<right)
        {
          mid = left + ((right - left) >> 1);
          if (nums[mid] > nums[right])
          left = mid + 1;
          else right = mid;
          //        	else if(nums[mid] < nums[right]) right=mid;
        }
        return nums[left];
