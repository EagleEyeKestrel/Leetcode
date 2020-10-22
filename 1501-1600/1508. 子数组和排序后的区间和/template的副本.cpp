//
//  main.cpp
//  就把所有的区间和放进ss数组然后排序，最后统计res。
//  区间和用前缀和处理一下，复杂度n2
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7, res = 0;
        int s[n + 1], ss[500510];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        int now = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                ss[now++] = s[j] - s[i - 1];
            }
        }
        sort(ss, ss + now);
        for(int i = left - 1; i <= right - 1; i++) {
            res = (res + ss[i]) % mod;
        }
        return res;
    }
};
