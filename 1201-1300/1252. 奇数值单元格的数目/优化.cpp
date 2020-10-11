//
//  main.cpp
//  优化的方法，其实只需要统计加了奇数次的行和列各几次，就可以了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int r[n], c[m];
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        for(auto &v: indices) {
            r[v[0]] = !r[v[0]];
            c[v[1]] = !c[v[1]];
        }
        int oddr = 0, oddc = 0;
        for(int i = 0; i < n; i++) {
            if(r[i]) oddr++;
        }
        for(int j = 0; j < m; j++) {
            if(c[j]) oddc++;
        }
        return oddr * (m - oddc) + oddc * (n - oddr);
    }
};
