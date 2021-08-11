//
//  main.cpp
//  数据范围很小，可以搜索，也可以直接递推，vis[i][j]=(vis[i-1][j] || vis[i][j-1]) && f(i,j)<=k
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(int x) {
        int res = 0;
        while (x > 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    int movingCount(int m, int n, int k) {
        int vis[m][n];
        memset(vis, 0, sizeof(vis));
        vis[0][0] = 1;
        int res = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i && !j) continue;
                if (f(i) + f(j) > k) continue;
                if (i) vis[i][j] |= vis[i - 1][j];
                if (j) vis[i][j] |= vis[i][j - 1];
                res += vis[i][j];
            }
        }
        return res;
    }
};
