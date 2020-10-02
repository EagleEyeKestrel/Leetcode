//
//  main.cpp
//  n^2的经典dp，用dp找到最长整除链，找的同时用prev标记一下前向元素
//  最后用prev找到序列，注意最后要反转一下
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxl = 0, maxp = 0;
        if(!n) return {};
        sort(nums.begin(), nums.end());
        int dp[n], prev[n];
        for(int i = 0; i < n; i++) prev[i] = i;
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(maxl < dp[i]) {
                maxl = dp[i];
                maxp = i;
            }
        }
        vector<int> res;
        while(1) {
            if(res.empty() || res.back() != nums[maxp]) res.push_back(nums[maxp]);
            else break;
            maxp = prev[maxp];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
