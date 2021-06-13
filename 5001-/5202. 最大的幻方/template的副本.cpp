//
//  main.cpp
//  由数据范围易知复杂度需要控制在O(n4)之内
//  穷举正方形需要穷举边长以及位置，是O(n3)，所以需要O(n)时间判断是否是一个幻方
//  两个斜对角很容易，关键是所有的行和列，需要用前缀和处理
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int s1[m + 1][n + 1], s2[m + 1][n + 1];
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        for (int i = 1; i <= m; i++) {
            int tmp = 0;
            for (int j = 1; j <= n; j++) {
                tmp += grid[i - 1][j - 1];
                s1[i][j] = tmp;
            }
        }
        for (int j = 1; j <= n; j++) {
            int tmp = 0;
            for (int i = 1; i <= m; i++) {
                tmp += grid[i - 1][j - 1];
                s2[i][j] = tmp;
            }
        }
        for (int res = min(m, n); res >= 2; res--) {
            for (int i = 0; i + res - 1 < m; i++) {
                for (int j = 0; j + res - 1 < n; j++) {
                    int flag = 1;
                    int v = s1[i + 1][j + res] - s1[i + 1][j];
                    for (int k = i; k < i + res; k++) {
                        if (s1[k + 1][j + res] - s1[k + 1][j] != v) {
                            flag = 0;
                            break;
                        }
                    }
                    for (int k = j; k < j + res; k++) {
                        if (s2[i + res][k + 1] - s2[i][k + 1] != v) {
                            flag = 0;
                            break;
                        }
                    }
                    int tmp1 = 0, tmp2 = 0;
                    for (int k = 0; k < res; k++) {
                        tmp1 += grid[i + k][j + k];
                        tmp2 += grid[i + res - 1 - k][j + k];
                    }
                    if (tmp1 != v || tmp2 != v) flag = 0;
                    if (flag) return res;
                }
            }
        }
        return 1;
    }
};
