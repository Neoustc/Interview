class Solution {
public:
   vector<int> twoSum(vector<int> &numbers, int target)
 {
 	vector<int> index;
 	int n = numbers.size();
 	for (int i = 0; i < n; ++i)
 		index.push_back(i);
 	Qsort(numbers, index, 0, n - 1);
 	int i = 0, j = n - 1, sum = 0;
 	while (i < j)
 	{
 		sum = numbers[i] + numbers[j];
 		if (sum == target)
 		return {min(index[i], index[j]) + 1, max(index[i], index[j]) + 1};
 		else if (sum > target) --j;
 		else ++i;
 	}
 }

 void Qsort (vector<int> & v1, vector<int> & v2, int low , int high)
 {
 	int mid, key, i, j;
 	if (low < high)
 	{
 		mid = low + (high - low) / 2;
 		swap(v1[mid], v1[low]);
 		swap(v2[mid], v2[low]);
 		key = v1[low];
 		i = low + 1;
 		j = high;
 		while (i <= j)
 		{
 			while (i <= j && v1[i] <= key)
 				++i;
 			while (i <= j && v1[j] > key)
 				--j;
 			if (i < j)
 			{
 				swap(v1[i], v1[j]);
 				swap(v2[i], v2[j]);
 			}
 		}
 		swap(v1[low], v1[j]);
 		swap(v2[low], v2[j]);
 		Qsort(v1, v2, low, j - 1);
 		Qsort(v1, v2, j + 1, high);
 	}
 }
};
