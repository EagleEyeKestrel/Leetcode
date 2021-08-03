//
//  main.cpp
//  很简单的dp，没做出来。。
//  本来想贪心做，以为是要取从头开始前缀和最大的部分，但边界情况处理比较烦
//  可以去看官方题解。这个题的关键就是每个人每次取的分数都是一个前缀和
//  用dp[i]表示当前可选择的石头的范围是[i,n-1]
//  如果取i，那分数就是pre[i]-dp[i+1]
//  关键是其他的所有情况都可以化简为dp[i+1]，很巧妙
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        int pre[n], dp[n];
        for (int i = 0; i < n; i++) pre[i] = stones[i] + (i ? pre[i - 1] : 0);
        //dp[i] = max(pre[i]-dp[i+1], pre[i+1]-dp[i+2]...)
        //      = max(pre[i]-dp[i+1], dp[i+1]);
        dp[n - 1] = pre[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            dp[i] = max(dp[i + 1], pre[i] - dp[i + 1]);
        }
        return dp[1];
    }
};
