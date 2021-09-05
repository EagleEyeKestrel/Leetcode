//
//  main.cpp
//  我的方法，一看就是区间dp的题。以前做的区间dp，都是
//  dp[l][r]=max{dp[l+1][r]+score[l], dp[l][r-1]+score[r]}这种类型的
//  但是复杂度都是O(n2)的。这里nums的长度是10^5级别，不可以直接区间dp
//  但注意到mul数组的长度是千级别，仔细一想，nums只有前m个元素和后m个元素可能会被拿出
//  所以预处理一下，如果nums长度大于2m，变成2m长度，然后区间dp
//  算dp[i][j]时，这是第i+(n-1-j)次操作，所以乘的会是mul[i+n-1-j]
//  会遇到i+n-1-j越界的情况，说明剩余这个区间需要大于m次操作，是不可能的，赋0
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        int v[2010];
        if (n > 2 * m) {
            n = 2 * m;
            for (int i = 0; i < m; i++) v[i] = nums[i];
            for (int i = 0; i < m; i++) v[m + i] = nums[nums.size() - m + i];
        } else {
            for (int i = 0; i < nums.size(); i++) v[i] = nums[i];
        }
        int dp[n][n];
        for (int i = 0; i < n; i++) {
            if (n - 1 <= m - 1) dp[i][i] = v[i] * multipliers[m - 1];
            else dp[i][i] = 0;
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (i + n - j - 1 <= m - 1) {
                    dp[i][j] = max(v[i] * multipliers[i + n - j - 1] + dp[i + 1][j], v[j] * multipliers[i + n - j - 1] + dp[i][j - 1]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][n - 1];
    }
};
