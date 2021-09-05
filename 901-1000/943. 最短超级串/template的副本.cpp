//
//  main.cpp
//  不难想到对words用状压。对状态mask，不难想到穷举最后一个字符串，但考虑到最后一个字符串会和之前的有重复，所以不能简单的用数组dp[mask]来做
//  定义dp[mask][j]是选取状态为mask的单词，并且最后一个字符串是j
//  那么穷举之前一段的最后一个字符串k，递推方程写在注释里，其中overlap[k][j]指的是words[k]和words[j]的最大重合部分，预处理一下。
//  为了得到最终的字符串，还需要加一个追踪数组pre[mask][j]，表示dp[mask][j]取到最小值时，之前的最后一个字符串k
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        int dp[1 << n][n], pre[1 << n][n], overlap[n][n];
        //dp[mask][j]=min{dp[mask^j][k]+len[j]-overlap[k][j]}
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int l1 = words[i].size(), l2 = words[j].size();
                for (int k = min(l1, l2); k >= 0; k--) {
                    if (words[i].substr(l1 - k) == words[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int j = 0; j < n; j++) {
                if ((mask >> j & 1) == 0) continue;
                dp[mask][j] = INT_MAX;
                int preState = mask ^ (1 << j);
                if (preState == 0) {
                    dp[mask][j] = words[j].size();
                    pre[mask][j] = -1;
                    continue;
                }
                for (int k = 0; k < n; k++) {
                    if ((preState >> k & 1) == 0) continue;
                    if (dp[preState][k] + words[j].size() - overlap[k][j] < dp[mask][j]) {
                        dp[mask][j] = dp[preState][k] + words[j].size() - overlap[k][j];
                        pre[mask][j] = k;
                    }
                }
            }
        }
        string res;
        int pos, maxl = INT_MAX, last = -1, mask = (1 << n) - 1;
        for (int j = 0; j < n; j++) {
            if (dp[(1 << n) - 1][j] < maxl) {
                maxl = dp[(1 << n) - 1][j];
                pos = j;
            }
        }
        while (pos != -1) {
            string add = last == -1 ? words[pos] : words[pos].substr(0, words[pos].size() - overlap[pos][last]);
            res = add + res;
            last = pos;
            pos = pre[mask][pos];
            mask ^= (1 << last);
        }
        return res;
    }
};
