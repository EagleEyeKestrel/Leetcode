//
//  main.cpp
//  二维前缀和裸题
//  可以用s[i][j]表示matrix[1][1]到matrix[i][j]这个矩阵的和（此处）
//  也可以用s[i][j]表示matrix[i][1]到matrix[i][j]这个矩阵的和
//  Copyright © 2021 ji luyang. All rights reserved.
//

class NumMatrix {
public:
    int s[1010][1010];
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return s[row2 + 1][col2 + 1] - s[row1][col2 + 1] - s[row2 + 1][col1] + s[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
