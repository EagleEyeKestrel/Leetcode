//
//  main.cpp
//  算是LIS问题的变种
//  用dp[i]表示 当保留每个字符串的s[i]时 之前可以保留下来的最大长度
//  那么穷举每个字符串之前留下来的是dp[j]，然后检查每个字符串，是否s[j]都<=s[i]，如果可以，就更新dp[i]=max(dp[i],dp[j]+1)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), l = strs[0].size(), maxv = 1;
        int dp[l];
        dp[0] = 1;
        for (int i = 1; i < l; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                int flag = 1;
                for (int k = 0; k < n; k++) {
                    if (strs[k][j] > strs[k][i]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) dp[i] = max(dp[i], dp[j] + 1);
            }
            maxv = max(maxv, dp[i]);
        }
        return l - maxv;
    }
};
