//
//  main.cpp
//  数据范围是O(n2)的
//  所以可以预处理所有点之间的距离，然后就变成了最小生成树问题
//  直接套Prim算法
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        int cost[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) cost[i][j] = 0;
                else cost[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        }
        int vis[n], lowcost[n];
        memset(vis, 0, sizeof(vis));
        vis[0] = 1;
        for (int i = 0; i < n; i++) {
            lowcost[i] = cost[0][i];
        }
        for (int i = 1; i < n; i++) {
            int minv = INT_MAX, j;
            for (int k = 0; k < n; k++) {
                if (!vis[k] && lowcost[k] < minv) {
                    minv = lowcost[k];
                    j = k;
                }
            }
            vis[j] = 1;
            res += lowcost[j];
            for (int k = 0; k < n; k++) {
                if (!vis[k] && cost[j][k] < lowcost[k]) {
                    lowcost[k] = cost[j][k];
                }
            }
        }
        return res;
    }
};
