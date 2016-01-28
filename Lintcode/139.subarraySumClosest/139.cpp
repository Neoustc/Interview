class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
  //  ;
 
  struct myclass
   {
   	int* sum;
   	bool operator()(int i , int j){return sum[i] < sum[j];}
   }myobject; 
   
   vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        int n = nums.size();
        vector<int> res(2);
       //  vector<int> sum(n);
        int * sum = new int[n];
        int i;
        for (i = 1, sum[0] = nums[0]; i < nums.size(); ++i)
            sum[i] = sum [i - 1] + nums[i];
        vector<int> index(n);
        iota(index.begin(), index.end(), 0);
         //sort(index.begin(), index.end(), [](int i, int j){return sum[i] < sum[j];});
        //sort(index.begin(), index.end(), [](int i, int j){return i < j;});
       //vector<int> myclass::sum = sum;
       myobject.sum = sum;
       sort(index.begin(), index.end(), myobject);
        int closest = INT_MAX;
        for (int i = 1; i < n; ++i)
        {
        	int diff = sum[index[i]] - sum[index[i - 1]];
            if (!diff)
            return { min(index[i], index[i - 1]) + 1, max(index[i], index[i- 1])};
        	if (closest > abs(diff))
        	{
        		closest = abs(diff);
      			res[0] = min(index[i], index[i - 1]) + 1;
      			res[1] = max(index[i], index[i- 1]);
        	}
        }
        return res;       
    }
};
