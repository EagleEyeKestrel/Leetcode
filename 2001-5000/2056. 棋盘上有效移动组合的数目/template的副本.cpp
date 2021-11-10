//
//  main.cpp
//  比较无聊的大模拟。。
//  我的想法是用个op数组，表示几个棋子分别做的操作，{方向，步数}
//  穷举，穷举完进行check。。看每一步是否会有重叠
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int sz[3] = {4, 8, 4};
    int dx[3][8] = {{-1, 0, 0, 1},{-1, -1, -1, 0, 0, 1, 1, 1},{-1, -1, 1, 1} };
    int dy[3][8] = {{0, -1, 1, 0},{-1, 0, 1, -1, 1, -1, 0, 1},{-1, 1, -1, 1}};
    int n;
    vector<vector<int>> init;
    int res = 0;
    bool inmap(int i, int j) {
        return i >= 0 && i < 8 && j >= 0 && j < 8;
    }
    void dfs(vector<string> &pieces, int depth, vector<pair<int, int>> &ops) {
        if (depth == n) {
            int nowx[n], nowy[n], id[n];
            for (int i = 0; i < n; i++) nowx[i] = init[i][0], nowy[i] = init[i][1];
            for (int i = 0; i < n; i++) {
                if (pieces[i] == "rook") id[i] = 0;
                else if (pieces[i] == "queen") id[i] = 1;
                else id[i] = 2;
            }
            int maxd = 0;
            for (auto &pi: ops) maxd = max(maxd, pi.second);
            int flag = 1;
            for (int step = 1; step <= maxd; step++) {
                int tmp[8][8];
                memset(tmp, 0, sizeof(tmp));
                for (int i = 0; i < n; i++) {
                    if (ops[i].second < step) {
                        int x = nowx[i], y = nowy[i];
                        if (tmp[x][y] == 1) {
                            flag = 0;
                            break;
                        }
                        tmp[x][y] = 1;
                        continue;
                    }
                    int x = nowx[i], y = nowy[i];
                    int op = ops[i].first;
                    x += dx[id[i]][op], y += dy[id[i]][op];
                    if (tmp[x][y] == 1) {
                        flag = 0;
                        break;
                    }
                    if (!flag) break;
                    tmp[x][y] = 1;
                    nowx[i] = x, nowy[i] = y;
                }
                if (!flag) break;
            }
            res += flag;
            return;
        }
        int id;
        if (pieces[depth] == "rook") id = 0;
        else if (pieces[depth] == "queen") id = 1;
        else id = 2;
        for (int i = 0; i < sz[id]; i++) {
            int x = init[depth][0], y = init[depth][1];
            for (int j = 1; j <= 8; j++) {
                int newx = x + j * dx[id][i], newy = y + j * dy[id][i];
                if (!inmap(newx, newy)) break;
                ops.push_back({i, j});
                dfs(pieces, depth + 1, ops);
                ops.pop_back();
            }
        }
        ops.push_back({0, 0});
        dfs(pieces, depth + 1, ops);
        ops.pop_back();
    }
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        n = pieces.size();
        vector<pair<int, int>> ops;
        for (auto &v: positions) v[0]--, v[1]--;
        init = positions;
        dfs(pieces, 0, ops);
        return res;
    }
};
