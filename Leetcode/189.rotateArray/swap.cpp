 void rotate(int nums[], int n, int k) 
    {
//Every swap will put one number into its correct position, so the running time is O(n)
//     	at first, nums[] is [1,2,3,4,5,6,7], n is 7, k is 3

// after first outer loop, nums[] is [4,1,2,3], n is 4, k is 3

// after second outer loop, nums[] is [4], n is 1, k is 0

// loop ends.
        int start = 0;
        for (; k = k%n; n -= k, start += k)
        {
            // Swap the last k elements with the first k elements. 
            // The last k elements will be in the correct positions
            // but we need to rotate the remaining (n - k) elements 
            // to the right by k steps.
            for (int i = 0; i < k; i++)
            {
                swap(nums[start + i], nums[start + n - k + i]);
            }
        }
    }
