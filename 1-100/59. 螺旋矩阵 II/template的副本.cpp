//
//  main.cpp
//  设置四个方向向量，依次走。每次要么是不在矩阵内了，要么是走过了，就换方向
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[4] = {0, 1, 0, -1};
    int direy[4] = {1, 0, -1, 0};
    int inmap(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i = 0, j = 0, now = 1, k = 0;
        while(1) {
            res[i][j] = now++;
            if(now > n * n) break;
            while(!inmap(i + direx[k], j + direy[k], n) || res[i + direx[k]][j + direy[k]]) k = (k + 1) % 4;
            i = i + direx[k];
            j = j + direy[k];
        }
        return res;
    }
};
