int findKthLargest(vector<int> & nums, int k)
	{
		priority_queue<int> pq(nums.begin(), nums.end());//default is max_heap;
		for (int i = 0; i < k - 1; ++i)
			pq.pop();
		return pq.top();
	} 
