//
//  main.cpp
//  想复杂了，其实就找到s中最长回文子序列，然后剩余的元素再插一遍就好了，有n-p[0][n-1]个
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int p[n][n];
        for (int i = 0; i < n; i++) p[i][i] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    p[i][j] = j - i > 1 ? 2 + p[i + 1][j - 1] : 2;
                } else {
                    p[i][j] = max(p[i + 1][j], p[i][j - 1]);
                }
            }
        }
        return n - p[0][n - 1];
    }
};
