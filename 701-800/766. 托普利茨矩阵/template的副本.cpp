//
//  main.cpp
//  穷举每一条对角线
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int k = m - 1; k >= 1 - n; k--) {
            for(int i = max(1, k + 1), j = max(1, 1 - k); i < m && j < n; i++, j++) {
                if(matrix[i - 1][j - 1] != matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
