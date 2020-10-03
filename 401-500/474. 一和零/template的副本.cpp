//
//  main.cpp
//  比较基础的二维背包
//  预处理每个str 0和1的数量，然后压缩成二维进行dp
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int one[strs.size() + 1], zero[strs.size() + 1], dp[m + 1][n + 1];
        for(int i = 1; i <= strs.size(); i++) {
            int cnt1 = 0, cnt0 = 0;
            for(char c: strs[i - 1]) {
                if(c == '0') cnt0++;
                else cnt1++;
            }
            one[i] = cnt1;
            zero[i] = cnt0;
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= strs.size(); i++) {
            for(int j = m; j >= zero[i]; j--) {
                for(int k = n; k >= one[i]; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zero[i]][k - one[i]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
