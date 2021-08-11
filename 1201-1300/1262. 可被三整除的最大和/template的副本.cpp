//
//  main.cpp
//  开始想到一种做法。将nums里的数字分成三组，mod3=0的直接加，然后mod3=1或2的分到两个列表里
//  然后根据各自模3的数量进行讨论。但没有发现什么很简单的讨论方法
//  改用dp，dp[i]表示 遍历到num时 mod3余数为i的最大和
//  要注意dp[0]=0是有意义的，可以直接加，但dp[1]=0代表不存在，所以要特殊判断一下
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int dp[3];
        memset(dp, 0, sizeof(dp));
        for (int num: nums) {
            int a = dp[0], b = dp[1], c = dp[2];
            if (num % 3 == 0) {
                dp[0] += num;
                if (dp[1]) dp[1] += num;
                if (dp[2]) dp[2] += num;
            }
            if (num % 3 == 1) {
                dp[0] = max(a, c ? c + num : 0);
                dp[1] = max(b, a + num);
                dp[2] = max(c, b ? b + num : 0);
            }
            if (num % 3 == 2) {
                dp[0] = max(a, b ? b + num : 0);
                dp[1] = max(b, c ? c + num : 0);
                dp[2] = max(c, a + num);
            }
        }
        return dp[0];
    }
};
