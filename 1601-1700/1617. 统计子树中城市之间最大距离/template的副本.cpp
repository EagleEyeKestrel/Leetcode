//
//  main.cpp
//  好久没ak周赛了。。这题我看到n<=15就知道肯定暴力就能过
//  思路是枚举所有的点子集，然后判断一下是否联通，最后计算这个子集的距离最大值，加到res数组里
//  枚举点的子集，二进制枚举就行了，然后用ps标记当前的点是哪些，pnum是有多少个点
//
//  判断是否联通，这里就直接dfs了，大小为1的子集直接不考虑了，vis数组用来标记访问
//  dfs完了now表示可以达到几个点，如果联通，随便从一个lastp出发一定能达到pnum个
//
//  计算子集的距离最大值，直接floyd得到两两之间的最短距离
//  复杂度大概是O(2^n n^2)，不会超的。一开始在里面用了一个set一个vector，居然超时了，换成ps数组就过了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int g[16][16];
    int now;
    int vis[16];
    int dist[16][16];
    void dfs(int i, int n, int* ps) {
        vis[i] = 1;
        now++;
        for(int j = 1; j <= n; j++) {
            if(g[i][j] && !vis[j] && ps[j]) {
                dfs(j, n, ps);
            }
        }
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> res(n - 1, 0);
        memset(g, 0, sizeof(g));
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dist[i][j] = 100;
        for(auto &edge: edges) {
            g[edge[0]][edge[1]] = 1;
            g[edge[1]][edge[0]] = 1;
            dist[edge[0]][edge[1]] = 1;
            dist[edge[1]][edge[0]] = 1;
        }
        for(int i = 1; i <= n; i++) dist[i][i] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++) {
                    if(dist[j][k] > dist[j][i] + dist[i][k]) dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
        for(int i = 1; i < 1 << n; i++) {
            int ps[n + 1], pnum = 0, lastp;
            memset(ps, 0, sizeof(ps));
            for(int j = 0; j < 20; j++) {
                if((i >> j) & 1) {
                    ps[j + 1] = 1;
                    pnum++;
                    lastp = j + 1;
                }
            }
            if(pnum < 2) continue;
            memset(vis, 0, sizeof(vis));
            now = 0;
            dfs(lastp, n, ps);
            int maxd = 0;
            if(now == pnum) {
                for(int i = 1; i <= n; i++) {
                    for(int j = i + 1; j <= n; j++) {
                        if(ps[i] && ps[j])
                        maxd = max(maxd, dist[i][j]);
                    }
                }
                res[maxd - 1]++;
            }
        }
        return res;
    }
};
