//
//  main.cpp
//  挺无聊的模拟。。好几次不想做，今天做掉拉倒了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[4] = {0, 1, 0, -1};
    int direy[4] = {1, 0, -1, 0};
    string s = "RDLU";
    vector<string> printKMoves(int K) {
        char grid[5000][5000];
        memset(grid, 0, sizeof(grid));
        int x = 2500, y = 2500, nowdir = 0;
        int minx = 2500, miny = 2500, maxx = 2500, maxy = 2500;
        grid[x][y] = '_';
        while(K--) {
            if(grid[x][y] == '_') {
                nowdir = (nowdir + 1) % 4;
                grid[x][y] = 'X';
                x += direx[nowdir];
                y += direy[nowdir];
            } else {
                nowdir = (nowdir + 3) % 4;
                grid[x][y] = '_';
                x += direx[nowdir];
                y += direy[nowdir];
            }
            minx = min(minx, x);
            maxx = max(maxx, x);
            maxy = max(maxy, y);
            miny = min(miny, y);
            if(!grid[x][y]) grid[x][y] = '_';
        }
        vector<string> res;
        for(int i = minx; i <= maxx; i++) {
            string tmp = "";
            for(int j = miny; j <= maxy; j++) {
                if(i == x && j == y) {
                    tmp.push_back(s[nowdir]);
                } else if(!grid[i][j]) {
                    tmp.push_back('_');
                } else {
                    tmp.push_back(grid[i][j]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
