//
//  main.cpp
//  用一个集合存nums1里的所有数。然后对于nums2里的每个数，去找>=nums2[i]和<nums2[i]的最接近的数，看一次更改最多能将绝对值缩小多少
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, mod = 1e9 + 7, n = nums1.size();
        set<int> s;
        for (int i = 0; i < n; i++) {
            res = (res + abs(nums1[i] - nums2[i])) % mod;
            s.insert(nums1[i]);
        }
        int maxv = 0;
        for (int i = 0; i < n; i++) {
            auto p1 = s.lower_bound(nums2[i]);
            int mind = abs(*p1 - nums2[i]);
            p1--;
            mind = min(mind, abs(*p1 - nums2[i]));
            maxv = max(maxv, abs(nums1[i] - nums2[i]) - mind);
        }
        return (res - maxv + mod) % mod;
    }
};
