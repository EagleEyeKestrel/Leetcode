//
//  main.cpp
//  容易发现dp[i] = min { dp[i - 1], dp[i - 2], ... , dp[i - k] } + nums[i]
//  dp + 滑动窗口最大值问题，deque维护上面说的区间里的最小值(的索引)，复杂度O(n)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        deque<int> q;
        q.push_back(0);
        for (int i = 1; i < n; i++) {
            dp[i] = dp[q.front()] + nums[i];
            while (!q.empty() && q.front() <= i - k) q.pop_front();
            while (!q.empty() && dp[q.back()] <= dp[i]) q.pop_back();
            q.push_back(i);
        }
        return dp[n - 1];
    }
};
