//
//  main.cpp
//  状压+枚举子集。我们可以思考，对于dp[mask]，穷举之前修的所有课程的子集sub，怎么看能否转移呢？
//  第一个问题，sub自身是否有效。可以进行预处理，查看sub里是否有哪个课程完成了但其先修课却没有
//  第二个问题，一学期不能超过k，这很简单，直接count一下
//  第三个问题，修完sub之后，能否在一学期修完mask^sub?
//  这个略难一些，但实际上只需看mask^sub里所有的先修课，是否全部在sub里即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        int dp[1 << n], valid[1 << n], pre[1 << n];
        vector<int> dep[16];
        for (auto &v: relations) dep[v[1] - 1].push_back(v[0] - 1);
        for (int mask = 0; mask < 1 << n; mask++) {
            int flag = 1;
            for (int v = 0; v < n && flag; v++) {
                if (mask >> v & 1) {
                    for (int u: dep[v]) {
                        if ((mask >> u & 1) == 0) {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
            valid[mask] = flag;
        }
        for (int mask = 0; mask < 1 << n; mask++) {
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) {
                    for (int u: dep[i]) {
                        tmp |= (1 << u);
                    }
                }
            }
            pre[mask] = tmp;
        }
        dp[0] = 0;
        for (int mask = 1; mask < 1 << n; mask++) {
            dp[mask] = 1e9;
            for (int sub = mask - 1; ; sub = (sub - 1) & mask) {
                if (!valid[sub] || __builtin_popcount(mask ^ sub) > k) {
                    if (sub == 0) break;
                    continue;
                }
                int need = pre[(mask ^ sub)], flag = 1;
                for (int i = 0; i < n; i++) {
                    if ((need >> i & 1) && (sub >> i & 1) == 0) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) dp[mask] = min(dp[mask], dp[sub] + 1);
                if (sub == 0) break;
            }
        }
        return dp[(1 << n) - 1];
    }
};
