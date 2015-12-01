//return the last negative
//it's O(NLOGN) space  and time complexity
int helper2(vector<int> &nums, int left, int right)
{
	if(left  > right) return -1;
	if(left == right ){
		if (nums[left] < 0) return left;
		else return -1;
	}
	if(right - left == 1){
		if(nums[left] < 0 && nums[right] < 0)
			return right;
		if(nums[left] < 0 && nums[right] > 0)
			return left;
		if(nums[left] > 0 && nums[right] > 0)
			return -1;
		swap(nums[left], nums[right]);
		 return left;
	}
		int mid = left + ((right - left) >> 1);
		int l = helper2(nums, left, mid);
		int r = helper2(nums, mid + 1, right);
		if(r == -1) return l;
		if(l == -1)
			{	
				flip(nums, left, mid + 1, r);
				return  r - (mid + 1 - left);
			}
		
		flip(nums, l + 1, mid + 1 , r);
		return r - (mid - l );
	
		
}
