//O(log (min(m,n)))
//http://blog.csdn.net/u010738052/article/details/50450153
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        int imin = 0, imax = m;
        int i = 0, num1, num2;
        while (imin <= imax)
        {
            int i = (imin + imax) / 2;
            int j =((m + n + 1) >> 1) - i;

            if (j > 0 && i < m && nums2[j - 1] > nums1[i])
                imin = i + 1;
            else if (i > 0 && j < n && nums1[i - 1] > nums2[j])
                imax = i - 1;
            else {
                if (i == 0)
                    num1 = nums2[j - 1];
                else if (j == 0)
                    num1 = nums1[i - 1];
                else num1 = max(nums1[i - 1], nums2[j - 1]);

                if ((m + n) % 2 == 1)
                    return num1;
                if (i == m)
                    num2 = nums2[j];
                else if (j == n)
                    num2 = nums1[i];
                else 
                    num2 = min(nums1[i], nums2[j]);
                return (num1 + num2) / 2.0;
            }
        }
     }  
