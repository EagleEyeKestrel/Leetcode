//
//  main.cpp
//  从车的位置往四个方向走，统计一下哪个方向能吃到子
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[4] = {-1, 0, 0, 1};
    int direy[4] = {0, -1, 1, 0};
    bool inmap(int i, int j) {
        return i >= 0 && i < 8 && j >= 0 && j < 8;
    }

    int numRookCaptures(vector<vector<char>>& board) {
        int Rx, Ry, res = 0;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(board[i][j] == 'R') {
                    Rx = i;
                    Ry = j;
                }
            }
        }
        for(int k = 0; k < 4; k++) {
            int nowx = Rx, nowy = Ry;
            while(inmap(nowx, nowy)) {
                if(board[nowx][nowy] == 'p') {
                    res++;
                    break;
                }
                if(board[nowx][nowy] == 'B') break;
                nowx += direx[k];
                nowy += direy[k];
            }
        }
        return res;
    }
};
