//
//  main.cpp
//  我的做法，复杂度(nmlogm)
//  首先arr2只起一个集合的作用，去重排序
//  dp[i][j]表示把arr1[i]变成arr2[j]的最少操作次数。
//  其中额外定义dp[i][m]是arr1[i]不变的情况。
//  当j in [0,m)，有第一行注释所示的方程，并需要额外判断一下dp[i-1][m]
//  用一个数组minv[j]维护dp[i-1][0]...dp[i-1][j]的最小值
//  对于dp[i][m]也类似处理，二分搜索一下arr2中的值，也是调minv就行了
//  对了。我居然不知道，unique一定要有序数组，WA了一次。。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int m = arr2.size();
        int dp[n][m + 1], minv[m + 1];
        for (int j = 0; j < m; j++) dp[0][j] = 1;
        dp[0][m] = 0;
        for (int i = 1; i < n; i++) {
            minv[0] = dp[i - 1][0];
            for (int j = 1; j < m; j++) minv[j] = min(dp[i - 1][j], minv[j - 1]);
            for (int j = 0; j < m; j++) {
                //dp[i][j]=min{dp[i-1][0]..dp[i-1][j-1]} + 1
                dp[i][j] = (j >= 1 ? minv[j - 1] + 1 : 1e9);
                if (arr2[j] > arr1[i - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][m] + 1);
                }
            }
            int id = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            //dp[i][m]=min{dp[i-1][0]...dp[i-1][id-1]}
            dp[i][m] = id >= 1 ? minv[id - 1] : 1e9;
            if (arr1[i] > arr1[i - 1]) {
                dp[i][m] = min(dp[i][m], dp[i - 1][m]);
            }
        }
        int res = INT_MAX;
        for (int j = 0; j <= m; j++) res = min(res, dp[n - 1][j]);
        return res >= 1e9 ? -1 : res;
    }
};
