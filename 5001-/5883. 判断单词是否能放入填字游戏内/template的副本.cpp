//
//  main.cpp
//  处理出所有的横/竖段，朴素判断能否填进去
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<pair<int, int>> line[m], ver[n];
        for (int i = 0; i < m; i++) {
            int j = 0;
            while (j < n) {
                if (board[i][j] == '#') {
                    j++;
                    continue;
                }
                int l = j;
                while (j + 1 < n && board[i][j + 1] != '#') j++;
                line[i].push_back({l, j});
                j++;
            }
        }
        for (int j = 0; j < n; j++) {
            int i = 0;
            while (i < m) {
                if (board[i][j] == '#') {
                    i++;
                    continue;
                }
                int l = i;
                while (i + 1 < m && board[i + 1][j] != '#') i++;
                ver[j].push_back({l, i});
                i++;
            }
        }
        for (int i = 0; i < m; i++) {
            for (auto &pi: line[i]) {
                int y1 = pi.first, y2 = pi.second;
                if (y2 - y1 + 1 != word.size()) continue;
                int flag = 1;
                for (int j = y1; j <= y2; j++) {
                    if (board[i][j] != ' ' && board[i][j] != word[j - y1]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) return true;
                flag = 1;
                for (int j = y1; j <= y2; j++) {
                    if (board[i][j] != ' ' && board[i][j] != word[word.size() - j + y1 - 1]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        for (int j = 0; j < n; j++) {
            for (auto &pi: ver[j]) {
                int x1 = pi.first, x2 = pi.second;
                if (x2 - x1 + 1 != word.size()) continue;
                int flag = 1;
                for (int i = x1; i <= x2; i++) {
                    if (board[i][j] != ' ' && board[i][j] != word[i - x1]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) return true;
                flag = 1;
                for (int i = x1; i <= x2; i++) {
                    if (board[i][j] != ' ' && board[i][j] != word[word.size() - i + x1 - 1]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }
};
