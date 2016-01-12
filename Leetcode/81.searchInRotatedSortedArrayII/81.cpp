//http://blog.csdn.net/u010738052/article/details/50507991
bool search(int A[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        //while (l < r && nums[l] == nums[l + 1]) l++; // skip duplicates from the left
        //  while (r > l && nums[r] == nums[r - 1]) r--; // skip duplicates from the right
        int m = l + (r - l)/2;
        if (A[m] == key) return true; //return m in Search in Rotated Array I
        if (A[l] < A[m]) { //left half is sorted
            if (A[l] <= key && key < A[m])
                r = m - 1;
            else
                l = m + 1;
        } else if (A[l] > A[m]) { //right half is sorted
            if (A[m] < key && key <= A[r])
                l = m + 1;
            else
                r = m - 1;
        } else l++; // skip the dups
    }
    return false;
