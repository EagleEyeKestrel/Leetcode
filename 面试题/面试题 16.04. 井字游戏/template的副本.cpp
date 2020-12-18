//
//  main.cpp
//  水题
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    inline int f(char c) {
        if (c == 'X') return 1;
        if (c == 'O') return -1;
        return 0;
    }
    string tictactoe(vector<string>& board) {
        int n = board.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp += f(board[i][j]);
                if (board[i][j] != ' ') cnt++;
            }
            if (tmp == n) return "X";
            if (tmp == -n) return "O";
            tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp += f(board[j][i]);
            }
            if (tmp == n) return "X";
            if (tmp == -n) return "O";
        }
        int tmp1 = 0, tmp2 = 0;
        for (int i = 0; i < n; i++) {
            tmp1 += f(board[i][i]);
            tmp2 += f(board[i][n - 1 - i]);
        }
        if (tmp1 == n || tmp2 == n) return "X";
        if (tmp1 == -n || tmp2 == -n) return "O";
        return cnt == n * n ? "Draw" : "Pending";
    }
};
