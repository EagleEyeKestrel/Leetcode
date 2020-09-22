//
//  main.cpp
//  以前我连这种题都不会做吗。。好菜
//  前缀和求完后，m记录之前出现过的前缀和的次数，累加就好了。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        int sum[n + 1];
        sum[0] = 0;
        for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i - 1];
        unordered_map<int, int> m;
        m[0] = 1;
        for(int i = 0; i < n; i++) {
            res += m[sum[i + 1] - k];
            m[sum[i + 1]]++;
        }
        return res;
    }
};
