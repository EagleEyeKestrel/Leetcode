//
//  main.cpp
//  第一次的做法，复杂度O(n^3 2^n)，dp[i][j][k]表示0-i 使用过的数状态为j，并且最后一个数为k的种类数
//  注意最后要除以每个数的重复排列数
//  当然用dfs也是可以的，而且估计更快，避免了一些不必要的状态计算
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int check(int x) {
        int a = sqrt(x);
        return a * a == x;
    }
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size(), res = 0;
        int fac[13];
        fac[1] = 1;
        for (int i = 2; i <= 12; i++) fac[i] = fac[i - 1] * i;
        unordered_map<int, int> mp;
        for (int num: nums) mp[num]++;
        int dp[n][1 << n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            dp[0][1 << i][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < (1 << n); j++) {
                if (__builtin_popcount(j) != i + 1) continue;
                for (int k = 0; k < n; k++) {
                    if ((j >> k & 1) == 0) continue;
                    int lastState = j ^ (1 << k);
                    for (int l = 0; l < n; l++) {
                        if (l != k && check(nums[k] + nums[l])) {
                            dp[i][j][k] += dp[i - 1][lastState][l];
                        }
                    }
                }
            }
        }
        for (int j = 0; j < (1 << n); j++) {
            for (int k = 0; k < n; k++) {
                res += dp[n - 1][j][k];
            }
        }
        for (auto [key, val]: mp) {
            if (val > 1) res /= fac[val];
        }
        return res;
    }
};
