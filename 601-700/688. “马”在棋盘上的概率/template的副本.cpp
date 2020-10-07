//
//  main.cpp
//  基础的k步dp问题。dp[k][i][j]表示从(i,j)k步仍在棋盘内的概率
//  当然k这一维也是可以优化掉的，这里没优化
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int direy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    bool inmap(int i, int j, int N) {
        return i >= 0 && i < N && j >= 0 && j < N;
    }
    double knightProbability(int N, int K, int r, int c) {
        double dp[K + 1][N][N];
        memset(dp, 0, sizeof(dp));
        for(int k = 0; k <= K; k++) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(!k) {
                        dp[k][i][j] = 1;
                        continue;
                    }
                    double tmp = 0;
                    for(int kk = 0; kk < 8; kk++) {
                        int newi = i + direx[kk], newj = j + direy[kk];
                        if(inmap(newi, newj, N)) tmp += dp[k - 1][newi][newj] / 8;
                    }
                    dp[k][i][j] = tmp;
                }
            }
        }
        return dp[K][r][c];
    }
};
