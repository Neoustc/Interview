// buildheap is O(n) in an amortized sense;
// O(klogn) for k times of max_heapify;
class Solution {
public:
	void buildheap(vector<int> & nums)
	{
		heap_size = nums.size();
		for (int i = (heap_size >> 1) - 1; i >= 0; --i) //start from the last non-leaf node;
		adjustHeap(nums, i);
	}

	void adjustHeap(vector<int> & nums, int i)
	{
		int left = i * 2 + 1;
		int right = i * 2 + 2;
		int max = i;
		if ( left < heap_size && nums[left] > nums[max] )
			max = left;
		if ( right < heap_size && nums[right] > nums[max] )
			max = right;
		if (max != i)
		{
			swap(nums[i], nums[max]);
			adjustHeap(nums, max); // adjust the children top - down
		}
	}

    int findKthLargest(vector<int>& nums, int k) {
		buildheap(nums);
		for (int i = 0; i < k; ++i)
		{
			swap(nums[0], nums[heap_size - 1]);
			heap_size--;
			adjustHeap(nums, 0);
		} 
		return nums[heap_size];
    }
private: 
	int heap_size;
};
