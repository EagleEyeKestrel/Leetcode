//
//  main.cpp
//  法三的做法优化到一维
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int superEggDrop(int k, int n) {
        //dp[i][j]=dp[i-1][j]+1+dp[i-1][j-1];
        int dp[k + 1];
        int i = 0;
        memset(dp, 0, sizeof(dp));
        while (dp[k] < n) {
            i++;
            for (int j = k; j >= 1; j--) {
                dp[j] += 1 + dp[j - 1];
            }
        }
        return i;
    }
};
