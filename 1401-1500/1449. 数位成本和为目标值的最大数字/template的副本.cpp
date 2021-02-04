//
//  main.cpp
//  完全背包，自己做出来了
//  我的思路，用dp[i][j]表示在总的cost为i，j开头的情况下，数字最大的长度
//  因为数字会很大，所以这里先得到最大长度。然后再倒推数字
//  -1表示不存在这样的数字。从target递推结果
//  另外一种更直接的方法，可以dp是一个string型数组，用个函数来进行字符串的大小比较
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int dp[target + 1][10];
        for (int j = 0; j < 10; j++) dp[0][j] = 0;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < 10; j++) dp[i][j] = -1;
        }
        for (int sum = 1; sum <= target; sum++) {
            for (int j = 1; j <= 9; j++) {
                if (sum < cost[j - 1]) continue;
                for (int k = 1; k <= 9; k++) {
                    if (dp[sum - cost[j - 1]][k] != -1) {
                        dp[sum][j] = max(dp[sum][j], dp[sum - cost[j - 1]][k] + 1);
                    }
                }
            }
        }
        string res;
        int left = target;
        while (left) {
            int maxl = 0, maxnum = -1;
            for (int i = 9; i > 0; i--) {
                if (dp[left][i] > maxl) {
                    maxl = dp[left][i];
                    maxnum = i;
                }
            }
            if (maxnum == -1) break;
            res.push_back(maxnum + '0');
            left -= cost[maxnum - 1];
        }
        return res.empty() ? "0" : res;
    }
};
