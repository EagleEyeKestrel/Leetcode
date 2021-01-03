//
//  main.cpp
//  log(m + n)的解法
//  关键是findKth函数，用来找到两个有序数组中的第k小的数
//  假设nums1[newi]是较小的一项，那么就会删除nums1[i]到nums1[newi]所有项
//  这些项一定是不超过第k小的
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        while (1) {
            if (i == m) return nums2[j + k - 1];
            if (j == n) return nums1[i + k - 1];
            if (k == 1) return min(nums1[i], nums2[j]);
            int newi = min(i + k / 2 - 1, m - 1);
            int newj = min(j + k / 2 - 1, n - 1);
            if (nums1[newi] <= nums2[newj]) {
                k -= newi - i + 1;
                i = newi + 1;
            } else {
                k -= newj - j + 1;
                j = newj + 1;
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2) {
            return findKth(nums1, nums2, (m + n + 1) / 2);
        }
        return (findKth(nums1, nums2, (m + n) / 2) + findKth(nums1, nums2, (m + n) / 2 + 1)) / 2.0;
    }
};
