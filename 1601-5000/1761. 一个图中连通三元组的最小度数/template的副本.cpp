//
//  main.cpp
//  暴力枚举就能过。。第一次知道400是一个典型的可以暴力穷举三元组的范围
//  预处理每一个点的度数cnt，对于每一个三元组，度数就是三个度数之和-6
//  另外，可以去看吴自华的题解，把无向图变成有向，复杂度降低到M的3/2次方
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int g[n + 1][n + 1], cnt[n + 1];
        memset(g, 0, sizeof(g));
        memset(cnt, 0, sizeof(cnt));
        for (auto &edge: edges) {
            g[edge[0]][edge[1]] = 1;
            g[edge[1]][edge[0]] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][j]) cnt[i]++;
            }
        }
        int res = INT_MAX;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if (!g[i][j] || !g[i][k] || !g[j][k]) continue;
                    int tmp = 0;
                    tmp += cnt[i] - 2 + cnt[j] - 2 + cnt[k] - 2;
                    res = min(res, tmp);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
