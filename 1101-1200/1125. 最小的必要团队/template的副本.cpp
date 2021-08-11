//
//  main.cpp
//  req_skills很少，考虑状态压缩req
//  dp[i][j]表示前i个人，具备j状态的skills 最少的人数。
//  dp[i][state]=min(dp[i-1][state], dp[i-1][state - skill] + 1)
//  关键是最后如何得到具体的人，想了一会。其实就可以看每个dp[i][j]和dp[i-1][j]是否相等
//  如果相等，说明可以不用到第i个人，nowi--；否则，就说明肯定用到了第i个人，算出新的状态
//  就是不知道为什么状态压缩这么慢。。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> mp;
        for (int i = 0; i < req_skills.size(); i++) mp[req_skills[i]] = i;
        int n = people.size(), m = req_skills.size();
        int dp[n][1 << m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << m); j++) dp[i][j] = 1e9;
        }
        int state0 = 0;
        for (string &s: people[0]) state0 |= (1 << mp[s]);
        for (int mask = state0; ; mask = (mask - 1) & state0) {
            dp[0][mask] = !!mask;
            if (mask == 0) break;
        }
        for (int i = 1; i < n; i++) {
            for (int state = 0; state < (1 << m); state++) {
                dp[i][state] = dp[i - 1][state];
                int skill = state;
                for (string &s: people[i]) {
                    int id = mp[s];
                    if (state >> id & 1) skill ^= (1 << id);
                }
                dp[i][state] = min(dp[i][state], dp[i - 1][skill] + 1);
            }
        }
        vector<int> res;
        int nowi = n - 1, nowState = (1 << m) - 1;
        while (1) {
            if (nowi < 0 || nowState == 0) break;
            if (nowi == 0 || dp[nowi][nowState] != dp[nowi - 1][nowState]) {
                res.push_back(nowi);
                for (string &s: people[nowi]) {
                    int id = mp[s];
                    if (nowState >> id & 1) nowState ^= (1 << id);
                }
            }
            nowi--;
        }
        return res;
    }
};
