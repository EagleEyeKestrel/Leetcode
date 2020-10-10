//
//  main.cpp
//  每次更新一个时间i。遍历所有clips，如果涵盖了时间i，那就更新。
//  时间比较宽裕，O(n2)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        long dp[110];
        dp[0] = 0;
        for(int i = 1; i <= T; i++) {
            dp[i] = INT_MAX;
            for(auto &clip: clips) {
                if(clip[0] <= i && clip[1] >= i) {
                    dp[i] = min(dp[i], dp[clip[0]] + 1);
                }
            }
            if(dp[i] == INT_MAX) return -1;
        }
        return dp[T];
    }
};
