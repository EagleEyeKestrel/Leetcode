//
//  main.cpp
//  看到一年前写的复杂的代码，感慨万千
//  用国王去找皇后更简单
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int direy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int inmap(int i, int j) {
        return i >= 0 && i < 8 && j >= 0 && j < 8;
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        int vis[8][8];
        memset(vis, 0, sizeof(vis));
        for(auto &q: queens) vis[q[0]][q[1]] = 1;
        for(int k = 0; k < 8; k++) {
            int nowx = king[0] + direx[k], nowy = king[1] + direy[k];
            while(inmap(nowx, nowy)) {
                if(vis[nowx][nowy]) {
                    res.push_back({nowx, nowy});
                    break;
                }
                nowx += direx[k];
                nowy += direy[k];
            }
        }
        return res;
    }
};
