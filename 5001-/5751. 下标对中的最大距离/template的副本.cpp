//
//  main.cpp
//  基础的双指针 或者二分查找 都可以
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), r = -1, res = 0;
        for (int l = 0; l < m; l++) {
            while (r + 1 < n && nums2[r + 1] >= nums1[l]) r++;
            res = max(res, r - l);
        }
        return res;
    }
};
