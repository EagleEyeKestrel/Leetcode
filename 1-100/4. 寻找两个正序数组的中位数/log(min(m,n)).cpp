//
//  main.cpp
//  更优的解法，只需要log(min(m, n))
//  转化成，找到最大的i，使得nums1[i-1] <= nums2[j]
//  这里的方法比较tricky，条件是l<=r，然后判断个成立，如果成立才更新m1 m2，然后更新l是变成i+1
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = m, halflen = (m + n + 1) / 2;
        int m1 = 0, m2 = 0;
        while (l <= r) {
            int i = (l + r + 1) >> 1, j = halflen - i;
            int nums1_i1 = i ? nums1[i - 1] : INT_MIN;
            int nums1_i = i == m ? INT_MAX : nums1[i];
            int nums2_j1 = j ? nums2[j - 1] : INT_MIN;
            int nums2_j = j == n ? INT_MAX : nums2[j];
            if (nums1_i1 <= nums2_j) {
                l = i + 1;
                m1 = max(nums1_i1, nums2_j1);
                if ((m + n) % 2 == 0) m2 = min(nums1_i, nums2_j);
                else m2 = m1;
            }
            else r = i - 1;
        }
        return (m1 + m2) / 2.0;
    }
};
