//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n / 2; j++) {
                swap(A[i][j], A[i][n - 1 - j]);
            }
            for(int j = 0; j < n; j++) {
                A[i][j] = !A[i][j];
            }
        }
        return A;
    }
};
