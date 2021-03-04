//
//  main.cpp
//  更好的解法，如果对envelopes排序，对第一个值升序，对第二个值降序排序，那么就只需要找第二个值的最长上升子序列
//  为什么第二个值是降序？可以排除[3,4], [3,5]这样的情况
//  然后最长上升子序列之前讲过，最优解是O(nlgn)的
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(), sz = 0;
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int dp[100010];
        for(int i = 0; i < n; i++) {
            if(!sz || envelopes[i][1] > dp[sz - 1]) {
                dp[sz++] = envelopes[i][1];
            } else {
                int id = lower_bound(dp, dp + sz, envelopes[i][1]) - dp;
                dp[id] = envelopes[i][1];
            }
        }
        return sz;
    }
};
