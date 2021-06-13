//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/110822233
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[1 << n], incom[1 << n];
        for(int i = 0; i < (1 << n); i++) {
            if(__builtin_popcount(i) == n / k) {
                int flag = 1, now = 0;
                int sub[20];
                for(int j = 0; j < n; j++) {
                    if((i >> j) & 1) {
                        sub[now++] = nums[j];
                    }
                }
                sort(sub, sub + now);
                for(int j = 1; j < now; j++) {
                    if(sub[j] == sub[j - 1]) {
                        flag = 0;
                        break;
                    }
                }
                if(!flag) {
                    incom[i] = -1;
                    continue;
                }
                incom[i] = sub[now - 1] - sub[0];
            } else {
                incom[i] = -1;
            }
        }
        dp[0] = 0;
        for(int i = 1; i < (1 << n); i++) {
            dp[i] = -1;
            if(__builtin_popcount(i) % (n / k) == 0) {
                for(int sub = i; sub; sub = (sub - 1) & i) {
                    if(dp[i ^ sub] != -1 && incom[sub] != -1) {
                        if(dp[i] == -1) {
                            dp[i] = dp[i ^ sub] + incom[sub];
                        } else {
                            dp[i] = min(dp[i], dp[i ^ sub] + incom[sub]);
                        }
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
