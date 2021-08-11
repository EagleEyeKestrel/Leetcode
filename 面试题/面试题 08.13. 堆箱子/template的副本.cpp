//
//  main.cpp
//  排序后就又变成了LIS问题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        sort(box.begin(), box.end());
        int n = box.size(), res = box[0][2];
        int dp[n];
        dp[0] = box[0][2];
        for (int i = 1; i < n; i++) {
            dp[i] = box[i][2];
            for (int j = 0; j < i; j++) {
                if (box[j][0] < box[i][0] && box[j][1] < box[i][1] && box[j][2] < box[i][2]) {
                    dp[i] = max(dp[i], dp[j] + box[i][2]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
