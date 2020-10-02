//
//  main.cpp
//  比较简单的dp，每位都不同那最多是十位数，注意额外讨论下n > 10
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int dp[11];
        dp[0] = 1;
        dp[1] = 10;
        for(int i = 2; i <= 10; i++) {
            dp[i] = dp[i - 1] +(11 - i) * (dp[i - 1] - dp[i - 2]);
        }
        if(n > 10) return dp[10];
        return dp[n];
    }
};
