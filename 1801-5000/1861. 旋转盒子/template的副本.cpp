//
//  main.cpp
//  也不难，先旋转，然后对每一列进行掉落处理
//  这里维护了一个变量now作为当前下落的位置，然后不断更新now
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - 1 - i] = box[i][j];
            }
        }
        for (int j = 0; j < m; j++) {
            int now = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (res[i][j] == '*') {
                    now = i - 1;
                }
                if (res[i][j] == '#') {
                    if (i < now) {
                        res[now][j] = '#';
                        now--;
                        res[i][j] = '.';
                    } else if (i == now) {
                        now--;
                    }
                }
            }
        }
        return res;
    }
};
