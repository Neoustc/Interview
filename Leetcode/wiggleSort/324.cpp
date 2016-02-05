//https://leetcode.com/discuss/77115/o-n-time-o-1-space-solution-with-detail-explanations
// (1) Elements that are larger than the median: we can put them in the first few odd slots;

// (2) Elements that are smaller than the median: we can put them in the last few even slots;

// (3) Elements that equal the median: we can put them in the remaining slots.

void wiggleSort(vector<int>& nums) {
	int n = nums.size();
	auto midptr = nums.begin() + n / 2;
	nth_element(nums.begin(), midptr, nums.end());
	int mid = *midptr;
	#define A(i) nums[(1 + 2 * (i)) % (n | 1)]

	int i = 0, j = 0, k = n - 1;
	while (j <= k){
		if (A(j) > mid)
			swap(A(i++), A(j++));
		else if (A(j) < mid)
			swap(A(j), A(k --));
		else 
			j++;
	}
}
