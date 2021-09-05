//
//  main.cpp
//  动态规划方法。
//  用dp[i]表示 组成长度差为i的两个组合里 短的那个的最长长度
//  优化到一维，每次讨论rods[i]是加在短头还是长头即可。主要是这个dp方式没想到
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int dp[5010];
        for (int i = 0; i <= 5000; i++) dp[i] = -1;
        dp[0] = 0;
        for (int val: rods) {
            int tmp[5010];
            memcpy(tmp, dp, sizeof(tmp));
            for (int i = 0; i + val <= 5000; i++) {
                if (dp[i] == -1) continue;
                //dp[i], i+dp[i]
                tmp[i + val] = max(tmp[i + val], dp[i]);
                if (i >= val) {
                    tmp[i - val] = max(tmp[i - val], dp[i] + val);
                } else {
                    tmp[val - i] = max(tmp[val - i], dp[i] + i);
                }
            }
            memcpy(dp, tmp, sizeof(tmp));
        }
        return dp[0] == -1 ? 0 : dp[0];
    }
};
