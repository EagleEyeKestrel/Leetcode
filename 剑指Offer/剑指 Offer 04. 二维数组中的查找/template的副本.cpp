//
//  main.cpp
//  很老的题目了，从右上角出发开始搜索
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        if (!m || !n) return false;
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
