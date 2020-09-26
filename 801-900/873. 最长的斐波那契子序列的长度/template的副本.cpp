//
//  main.cpp
//  dp[i][j]表示A[i],A[j]作为最后两项的序列的最长长度
//  这里更新的时候穷举了i和j，用map存序列，看是否存在前一项
//  写完才发现没必要，穷举j，前面两项双指针穷举即可，省了内存。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        int dp[n][n];
        unordered_map<int, int> m;
        int res = 0;
        for(int i = 0; i < n; i++) {
            m[A[i]] = i;
        }
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) dp[i][j] = 2;
        }
        for(int i = 1; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int k = A[j] - A[i];
                if(m.count(k) && m[k] < i) {
                    dp[i][j] = max(dp[i][j], dp[m[k]][i] + 1);
                    if(dp[i][j] > 2) res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};
