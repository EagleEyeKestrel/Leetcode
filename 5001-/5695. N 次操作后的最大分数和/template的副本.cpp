//
//  main.cpp
//  又是状态压缩穷举子集的题，现在做这种题已经没什么问题了
//  subset可以是最后一步的两个数，也可以是除了两个数的集合
//  要注意如果定义为除了两个数的集合，subset就可以取0，注意处理
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    inline int gcd(int x, int y) {
        return x % y ? gcd(y, x % y) : y;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int dp[1 << n];
        dp[0] = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            int bits1 = __builtin_popcount(mask);
            if (bits1 & 1) continue;
            dp[mask] = 0;
            for (int subset = mask; subset; subset = (subset - 1) & mask) {
                if (__builtin_popcount(subset) != 2) continue;
                int diff[2];
                int now = 0;
                for (int i = 0; i < n; i++) {
                    if ((subset >> i) & 1) {
                        diff[now++] = i;
                    }
                }
                dp[mask] = max(dp[mask], dp[mask ^ subset] + gcd(nums[diff[0]], nums[diff[1]]) * bits1 / 2);
            }
        }
        return dp[(1 << n) - 1];
    }
};
