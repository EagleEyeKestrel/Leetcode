//
//  main.cpp
//  开始用dp[j] + 1直接和maxl比，同时更新res，这样是不对的，不能在同时计算res
//  比如1243，当到了3的位置的时候，maxl已经是3，让cnt[3]直接+=dp[1]是不对的。
//  更新cnt[i]的时候应该把dp[j]+1和dp[i]相比，最后统一计数cnt
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0, n = nums.size(), maxl = 1;
        if(!n) return 0;
        int dp[n], cnt[n];
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            cnt[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if(dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxl = max(maxl, dp[i]);
        }
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxl) res += cnt[i];
        }
        return res;
    }
};
