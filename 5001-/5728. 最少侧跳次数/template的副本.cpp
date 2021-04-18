//
//  main.cpp
//  贪心，ne[i][j]表示，i位置处跑道j的下一个障碍物的位置
//  每次遇到障碍，优先跳到ne[i][j]更大的跑道。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size(), res = 0, now = 2;
        int ne[n + 1][3];
        int tmp[3];
        for (int i = 0; i < 3; i++) tmp[i] = 1e9;
        for (int i = n - 1; i >= 0; i--) {
            if (obstacles[i] == 1) tmp[0] = i;
            if (obstacles[i] == 2) tmp[1] = i;
            if (obstacles[i] == 3) tmp[2] = i;
            for (int j = 0; j < 3; j++) ne[i][j] = tmp[j];
        }
        for (int i = 0; i < n - 1; i++) {
            if (obstacles[i + 1] == now) {
                int nextNow, maxNext = -1;
                for (int j = 0; j < 3; j++) {
                    if (obstacles[i] == j + 1) continue;
                    if (maxNext < ne[i][j]) {
                        maxNext = ne[i][j];
                        nextNow = j;
                    }
                }
                res++;
                now = nextNow + 1;
            }
        }
        return res;
    }
};
