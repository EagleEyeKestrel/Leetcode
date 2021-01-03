//
//  main.cpp
//  等价于找target在arr里的最长子序列
//  等价于,target[i]对应i，看arr里的数的索引的最长递增子序列
//  用nlogn解法实现LIS问题
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    unordered_map<int, int> m;
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        for (int i = 0; i < n; i++) m[target[i]] = i;
        int dp[100010];
        int sz = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (!m.count(arr[i])) continue;
            if (!sz || m[arr[i]] > dp[sz - 1]) {
                dp[sz] = m[arr[i]];
                sz++;
            } else {
                int id = lower_bound(dp, dp + sz, m[arr[i]]) - dp;
                dp[id] = m[arr[i]];
            }
        }
        return n - sz;
    }
};
