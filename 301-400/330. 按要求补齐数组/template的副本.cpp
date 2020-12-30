//
//  main.cpp
//  没想到，感觉比较tricky
//  用miss表示遍历到当前最小的还表示不出来的数
//  如果接下来的nums[i] <= miss，那么不仅可以表示出miss，新的miss也应该是miss + nums[i]
//  如果nums[i] > miss，表示不出来，那么我们就补个miss
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1, res = 0, i = 0;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                res++;
            }
        }
        return res;
    }
};
