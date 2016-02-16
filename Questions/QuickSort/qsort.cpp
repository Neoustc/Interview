void quicksort(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		int l = left, r = right;
		int pivot = nums[left];
		while (l < r)
		{
			while (l < r && nums[r] >= pivot) r--;
			if (l < r) nums[l++] = nums[r];
			while (l < r && nums[l] <= pivot) ++l;
			if (l < r) nums[r--] = nums[l];
		}
		nums[l] = pivot;
		quicksort(nums, left, l - 1);
		quicksort(nums, l + 1, right);
	}
}
