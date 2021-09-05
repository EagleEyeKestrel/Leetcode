//
//  main.cpp
//  一个队内，分数按从年轻到年老一定是一个递增序列，所以可以dp
//  按年龄从低到高排序，然后找分数的递增序列
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size(), res = 0;
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end());
        int dp[n];
        for(int i = 0; i < n; i++) {
            dp[i] = v[i].second;
            for(int j = 0; j < i; j++) {
                if(v[j].second <= v[i].second) {
                    dp[i] = max(dp[i], dp[j] + v[i].second);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
