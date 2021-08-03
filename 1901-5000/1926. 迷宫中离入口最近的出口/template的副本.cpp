//
//  main.cpp
//  最基础的bfs
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int direx[4] = { -1, 0, 0, 1 };
    int direy[4] = { 0, -1, 1, 0 };
    bool inmap(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({ entrance[0], entrance[1] });
        maze[entrance[0]][entrance[1]] = '+';
        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto tmp = q.front();
                q.pop();
                if ((tmp.first == 0 || tmp.first == m - 1 || tmp.second == 0 || tmp.second == n - 1) && (tmp.first != entrance[0] || tmp.second != entrance[1])) {
                    return res;
                }
                for (int d = 0; d < 4; d++) {
                    int newx = tmp.first + direx[d], newy = tmp.second + direy[d];
                    if (inmap(newx, newy, m, n) && maze[newx][newy] == '.') {
                        q.push({ newx, newy });
                        maze[newx][newy] = '+';
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
