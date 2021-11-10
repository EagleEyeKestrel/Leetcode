//
//  main.cpp
//  2021年寒假的某次周赛出过一次类似的
//  分成两半的思想，状压穷举左半边的情况，那么右半边取的个数是固定的，把取得个数对应的和都放进数组，二分即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> l, r;
        for (int i = 0; i < n / 2; i++) l.push_back(nums[i]);
        for (int i = n / 2; i < n; i++) r.push_back(nums[i]);
        int s = 0;
        for (int x: nums) s += x;
        int sz = n / 2;
        int sl[1 << sz], sr[1 << sz];
        for (int mask = 0; mask < 1 << sz; mask++) {
            sl[mask] = 0;
            for (int i = 0; i < sz; i++) {
                if (mask >> i & 1) {
                    sl[mask] += l[i];
                }
            }
        }
        for (int mask = 0; mask < 1 << sz; mask++) {
            sr[mask] = 0;
            for (int i = 0; i < sz; i++) {
                if (mask >> i & 1) {
                    sr[mask] += r[i];
                }
            }
        }
        vector<int> sum[20];
        for (int mask = 0; mask < 1 << sz; mask++) {
            sum[__builtin_popcount(mask)].push_back(sr[mask]);
        }
        for (int i = 0; i <= sz; i++) {
            sort(sum[i].begin(), sum[i].end());
        }
        int res = abs(sl[(1 << sz) - 1] - sr[(1 << sz) - 1]);
        for (int mask = 0; mask < 1 << sz; mask++) {
            int sz1 = __builtin_popcount(mask), sz2 = sz - sz1;
            int id = lower_bound(sum[sz2].begin(), sum[sz2].end(), s / 2 - sl[mask]) - sum[sz2].begin();
            if (id < sum[sz2].size()) res = min(res, abs(s - 2 * (sl[mask] + sum[sz2][id])));
            if (id - 1 >= 0) res = min(res, abs(s - 2 * (sl[mask] + sum[sz2][id - 1])));
        }
        return res;
    }
};
