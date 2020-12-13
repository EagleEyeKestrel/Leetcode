//
//  main.cpp
//  简单题。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
    int direy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};
    bool inmap(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int tmp = M[i][j], cnt = 1;
                for(int k = 0; k < 8; k++) {
                    int ii = i + direx[k], jj = j + direy[k];
                    if(inmap(ii, jj, m, n)) {
                        tmp += M[ii][jj];
                        cnt++;
                    }
                }
                res[i][j] = tmp / cnt;
            }
        }
        return res;
    }
};
