//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/113759270
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size(), res = INT_MAX;
        if (n == 1) return abs(nums[0] - goal);
        int lsize = n >> 1;
        int l[1 << lsize], r[1 << (n - lsize)];
        for (int i = 0; i < (1 << lsize); i++) {
            for (int j = 0; j < lsize; j++) {
                l[i] = 0;
                if ((i >> j) & 1) {
                    l[i] = l[i ^ (1 << j)] + nums[j];
                    break;
                }
            }
        }
        for (int i = 0; i < (1 << (n - lsize)); i++) {
            for (int j = 0; j < n - lsize; j++) {
                r[i] = 0;
                if ((i >> j) & 1) {
                    r[i] = r[i ^ (1 << j)] + nums[j + lsize];
                    break;
                }
            }
        }
        for (int i = 0; i < (1 << lsize); i++) res = min(res, abs(l[i] - goal));
        for (int i = 0; i < (1 << (n - lsize)); i++) res = min(res, abs(r[i] - goal));
        sort(l, l + (1 << lsize));
        sort(r, r + (1 << (n - lsize)));
        for (int i = 0; i < (1 << lsize); i++) {
            int id = lower_bound(r, r + (1 << (n - lsize)), goal - l[i]) - r;
            if (id < (1 << (n - lsize))) res = min(res, abs(goal - l[i] - r[id]));
            if (id) res = min(res, abs(goal - l[i] - r[id - 1]));
        }
        return res;
    }
};
