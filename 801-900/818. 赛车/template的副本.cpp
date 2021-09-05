//
//  main.cpp
//  用dp[i]表示从0到达i最少要几步。关键是关于dp[i]，怎么求？
//  关键是穷举i之前的状态j。
//  第一种情况，从0开始一直加速，不掉头，直到超过i，然后掉头，对应cnt1情况
//  第二种情况，在i之前有过掉头，那就穷举第一次掉头之前加速了j次，然后掉头走了k步。
//  注意k可以为0，因为可以掉头然后不动，再掉头，使得速度重置
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int racecar(int target) {
        int dp[target + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= target; i++) {
            dp[i] = INT_MAX;
            int speed = 2, now = 1, cnt1 = 1;
            while (now < i) {
                now += speed;
                speed <<= 1;
                cnt1++;
            }
            if (now - i < i) dp[i] = min(cnt1 + (now == i ? 0 : 1 + dp[now - i]), dp[i]);
            for (int j = 1; j < cnt1; j++) {
                int l1 = (1 << j) - 1;
                for (int k = 0; ; k++) {
                    int l2 = (1 << k) - 1;
                    if (l2 >= l1) break;
                    dp[i] = min(j + 1 + k + 1 + dp[i - (l1 - l2)], dp[i]);
                }
            }
        }
        return dp[target];
    }
};
