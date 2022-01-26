//
//  main.cpp
//  哈哈，最水的困难题。直接二进制穷举
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int res = 0, n = statements.size();
        for (int mask = 0; mask < 1 << n; mask++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int p1 = mask >> i & 1, p2 = mask >> j & 1;
                    if (p1 && statements[i][j] != 2 && statements[i][j] != p2) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) res = max(res, __builtin_popcount(mask));
        }
        return res;
    }
};