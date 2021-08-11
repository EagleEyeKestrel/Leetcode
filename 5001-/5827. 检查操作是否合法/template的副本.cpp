//
//  main.cpp
//  有点复杂的模拟
//  WA了一次，一开始24行偷懒只写了ii!=i，事实上有可能是在同一行走的
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int direy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    bool inmap(int i, int j) {
        return i >= 0 && i < 8 && j >= 0 && j < 8;
    }
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        board[rMove][cMove] = color;
        int x = rMove, y = cMove;
        for (int k = 0; k < 8; k++) {
            int i = x + direx[k] * 2, j = y + direy[k] * 2;
            if (!inmap(i, j)) continue;
            while (inmap(i, j)) {
                if (board[i][j] == board[x][y]) {
                    int ii = x + direx[k], jj = y + direy[k], mid = board[ii][jj], flag2 = 1;
                    while (ii != i || jj != j) {
                        if (board[ii][jj] != mid || board[ii][jj] == '.' || board[ii][jj] == board[x][y]) {
                            flag2 = 0;
                            break;
                        }
                        ii += direx[k], jj += direy[k];
                    }
                    if (flag2) {
                        return true;
                    }
                }
                i += direx[k], j += direy[k];
            }
        }
        return false;
    }
};
