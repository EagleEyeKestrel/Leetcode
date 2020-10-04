//
//  main.cpp
//  比较直观的dp。 dp[k][i][j]表示用最多k步从(i,j)出界的路径数。
//  如果从i,j一步能出界，直接加一，否则，变成用最多k-1步从新的起点出界
//  当然空间上可以优化下，最外面k那层是不需要的，空间复杂度可以降到O(mn)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[4] = {-1, 0, 0, 1};
    int direy[4] = {0, -1, 1, 0};
    int inmap(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    int findPaths(int m, int n, int N, int targeti, int targetj) {
        int mod = 1e9 + 7;
        int dp[N + 1][m][n];
        memset(dp, 0, sizeof(dp));
        for(int k = 1; k <= N; k++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    for(int kk = 0; kk < 4; kk++) {
                        int newi = i + direx[kk], newj = j + direy[kk];
                        if(inmap(newi, newj, m, n)) {
                            dp[k][i][j] = (dp[k][i][j] + dp[k - 1][newi][newj]) % mod;
                        } else {
                            dp[k][i][j] += 1;
                        }
                    }
                }
            }
        }
        return dp[N][targeti][targetj] % mod;
    }
};
