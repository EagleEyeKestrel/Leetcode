//
//  main.cpp
//  老题了，双指针法
//  >target，说明这一列下面的数都不可能
//  <target，说明这一行都不可能了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
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
