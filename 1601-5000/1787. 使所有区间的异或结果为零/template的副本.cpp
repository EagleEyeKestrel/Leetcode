//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/114803967
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        unordered_map<int, int> mp[k];
        int sz[k];
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            mp[i].clear(), sz[i] = 0;
            for (int j = i; j < n; j += k) {
                mp[i][nums[j]]++;
                sz[i]++;
            }
        }
        int dp[1024];
        for (int i = 1; i < 1024; i++) dp[i] = 1e9;
        dp[0] = 0;
        for (int i = 0; i < k; i++) {
            int tmp[1024];
            int minv = *min_element(dp, dp + 1024);
            for (int j = 0; j < 1024; j++) tmp[j] = minv + sz[i];
            for (int j = 0; j < 1024; j++) {
                if (dp[j] == 1e9) continue;
                for (auto it : mp[i]) {
                    int key = it.first, cnt = it.second;
                    tmp[j ^ key] = min(tmp[j ^ key], dp[j] + sz[i] - cnt);
                }
            }
            memcpy(dp, tmp, sizeof(tmp));
        }
        return dp[0];
    }
};
