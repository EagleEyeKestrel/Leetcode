//
//  main.cpp
//  dfs设成bool还是void还是有区别的，要能够第一时间剪枝
//  一直以来我都是inmap + vis + dfs的写法，看了别人的写法好像更简洁一点
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[4] = {-1, 0, 0, 1};
    int direy[4] = {0, -1, 1, 0};
    int vis[256][256];
    bool inmap(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, int depth, string& word) {
        if (depth == word.size() - 1) return true;
        bool res = false;
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int ii = i + direx[k], jj = j + direy[k];
            if (inmap(ii, jj, board.size(), board[0].size()) && !vis[ii][jj] && board[ii][jj] == word[depth + 1]) {
                res = res || dfs(board, ii, jj, depth + 1, word);
            }
        }
        vis[i][j] = 0;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};
