//
//  main.cpp
//  最基本的dp，每个dp检查之前的dp[j-1]和dp[j]。
//  注意要给tmp[0]和tmp[i+1]赋一个最大值，来表示取不到，否则会变成随机值，不一定正确
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), res = INT_MAX;
        if(!n) return 0;
        if(n == 1) return triangle[0][0];
        int dp[n + 2];
        for(int i = 0; i < n + 2; i++) dp[i] = 1e9;
        dp[1] = triangle[0][0];
        for(int i = 2; i <= n; i++) {
            int tmp[n + 2];
            for(int j = 1; j <= i; j++) {
                tmp[j] = min(dp[j - 1], dp[j]) + triangle[i - 1][j - 1];
                if(i == n) res = min(res, tmp[j]);
            }
            tmp[0] = 1e9;
            tmp[i + 1] = 1e9;
            memcpy(dp, tmp, sizeof(tmp));
        }
        return res;
    }
};
