//if the array doesn't contain 0, 
//the result must be start from the begin or end with the last element;
//if the the array contains  0 , we just split the array by the 0 element.
 int maxProduct(vector<int> & nums)
 {
 	int n = nums.size();
 	int res = INT_MIN;
 	int backProduct = 1, frontProduct = 1;
 	for (int i = 0; i < n; ++i)
 	{
 		frontProduct *= nums[i];
 		backProduct *= nums[n - i - 1];
 		res = max(res, max(backProduct, frontProduct));
 		frontProduct = frontProduct == 0 ? 1 : frontProduct;
 		backProduct = backProduct == 0 ? 1 : backProduct; 
 	}
 	return res;
 }
