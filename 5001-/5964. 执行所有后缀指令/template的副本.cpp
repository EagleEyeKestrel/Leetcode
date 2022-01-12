//
//  main.cpp
//  数据范围是500，所以直接遍历暴力
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int n;
    bool inmap(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        int m = s.size();
        this->n = n;
        for (int i = 0; i < m; i++) {
            int x = startPos[0], y = startPos[1], nowmax = 0;
            for (int j = i; j < m; j++) {
                if (s[j] == 'U') x--;
                if (s[j] == 'D') x++;
                if (s[j] == 'L') y--;
                if (s[j] == 'R') y++;
                if (inmap(x, y)) {
                    nowmax++;
                } else {
                    break;
                }
            }
            res.push_back(nowmax);
        }
        return res;
    }
};
