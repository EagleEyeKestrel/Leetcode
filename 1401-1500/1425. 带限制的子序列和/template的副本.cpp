//
//  main.cpp
//  用dp[i]表示以nums[i]结尾的 最大子序列和
//  所以要得到i-k到i-1的最大dp[j]，所以用单调队列维护 滑动窗口最大值 即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), res = nums[0];
        int dp[n];
        deque<int> q;
        dp[0] = nums[0];
        q.push_back(0);
        for (int i = 1; i < n; i++) {
            if (q.front() < i - k) q.pop_front();
            dp[i] = nums[i];
            if (!q.empty()) dp[i] = max(dp[i], dp[q.front()] + dp[i]);
            while (!q.empty() && dp[q.back()] <= dp[i]) q.pop_back();
            q.push_back(i);
            res = max(res, dp[i]);
        }
        return res;
    }
};
