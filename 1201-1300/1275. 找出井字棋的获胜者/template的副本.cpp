//
//  main.cpp
//  水题。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int grid[3][3];
    int check() {
        for(int i = 0; i < 3; i++) {
            if (grid[i][0] + grid[i][1] + grid[i][2] == 3) return 1;
            if (grid[i][0] + grid[i][1] + grid[i][2] == -3) return -1;
            if (grid[0][i] + grid[1][i] + grid[2][i] == 3) return 1;
            if (grid[0][i] + grid[1][i] + grid[2][i] == -3) return -1;
        }
        int v1 = grid[0][0] + grid[1][1] + grid[2][2];
        int v2 = grid[0][2] + grid[1][1] + grid[2][0];
        if (v1 && v1 % 3 == 0) return v1 / 3;
        if (v2 && v2 % 3 == 0) return v2 / 3;
        return 0;
    }
    string tictactoe(vector<vector<int>>& moves) {
        memset(grid, 0, sizeof(grid));
        for(int i = 0; i < moves.size(); i++) {
            grid[moves[i][0]][moves[i][1]] = i % 2 ? -1 : 1;
            int res = check();
            if (res == 1) return "A";
            if (res == -1) return "B";
        }
        if (moves.size() < 9) return "Pending";
        return "Draw";
    }
};
