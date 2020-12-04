//
//  main.cpp
//  第二次做还是没能想到follow up
//  用降维的思想。matrix[i][j]为0时，标记matrix[0][j]和matrix[i][0]为0（反正本来就要变成0）
//  而第0行和第0列，是否含有0，用两个变量标记就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m) return ;
        int n = matrix[0].size();
        int row0 = 0, col0 = 0;
        for(int j = 0; j < n; j++) if(!matrix[0][j]) row0 = 1;
        for(int i = 0; i < m; i++) if(!matrix[i][0]) col0 = 1;
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(row0) {
            for(int j = 0; j < n; j++) matrix[0][j] = 0;
        }
        if(col0) {
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};
