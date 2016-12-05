
// private method.
// Find the kth number of nums1 and nums2. Here, the kth number should be the median.
double find_kth(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    // ???
    if (m > n)  return find_kth(nums2, nums1, k); // Raymond: no need to judge if n == 0.
    if (m == 0) return nums2[k - 1];              // k is the middle number of m.
    // ERROR: if (n == 0) return nums1[k - 1];
    if (k == 1) return min(nums1[0], nums2[0]);  // Raymond: the key point.

    // Raymond: the key point. 
    // Why not m/2 and n/2, because i1 and i2 depend on the value of k, not m and n, so we consider k/2 to be the pivot.  
    int i1 = min(k/2, m);  
    int i2 = k - i1;       

    if (nums1[i1 - 1] < nums2[i2 - 1]) {
        nums1.erase(begin(nums1), begin(nums1) + i1);
        return find_kth(nums1, nums2, k - i1);
    } else if (nums1[i1 - 1] > nums2[i2 - 1]) {
        nums2.erase(begin(nums2), begin(nums2) + i2);
        return find_kth(nums1, nums2, k - i2);
    } else {
        return nums1[i1 - 1];
    }
}

// public method
double findMedianOfSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int total = m + n;
    if (total % 2 != 0)
        return find_kth(nums1, nums2, total / 2 + 1);
    else
        return ((find_kth(nums1, nums2, total / 2) + \
                 find_kth(nums1, nums2, total / 2)) / 2.0);
}
