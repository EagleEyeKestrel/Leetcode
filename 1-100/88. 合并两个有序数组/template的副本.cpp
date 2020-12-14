//
//  main.cpp
//  典型的双指针，由于空缺元素在后面，所以p应该从后往前
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p = m + n - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] < nums2[p2]) {
                nums1[p--] = nums2[p2--];
            } else {
                nums1[p--] = nums1[p1--];
            }
        }
        while (p2 >= 0) nums1[p--] = nums2[p2--];
    }
};
