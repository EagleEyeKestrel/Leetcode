//
//  main.cpp
//  找到每个点往上/下/左/右最多连续的1的数量即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int a[n][n][4], vis[250010];
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        for (auto &mine: mines) vis[mine[0] * n + mine[1]] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int id1 = i * n + j, id2 = (n - 1 - i) * n + j;
                if (i == 0) a[i][j][0] = !vis[id1];
                else a[i][j][0] = vis[id1] ? 0 : a[i - 1][j][0] + 1;
                if (i == 0) a[n - 1 - i][j][1] = !vis[id2];
                else a[n - 1 - i][j][1] = vis[id2] ? 0 : a[n - i][j][1] + 1;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                int id1 = i * n + j, id2 = i * n + n - 1 - j;
                if (j == 0) a[i][j][2] = !vis[id1];
                else a[i][j][2] = vis[id1] ? 0 : a[i][j - 1][2] + 1;
                if (j == 0) a[i][n - 1 - j][3] = !vis[id2];
                else a[i][n - 1 - j][3] = vis[id2] ? 0 : a[i][n - j][3] + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = INT_MAX;
                for (int k = 0; k < 4; k++) tmp = min(tmp, a[i][j][k]);
                res = max(res, tmp);
            }
        }
        return res;
    }
};
