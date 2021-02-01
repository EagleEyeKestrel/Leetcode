//
//  main.cpp
//  这次最后一题比较简单
//  预处理所有的s[i][j]是否是回文串
//  然后穷举两个分界点判断即可，复杂度O(n2)稳过
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        int p[n][n];
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; i++) p[i][i] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                p[i][j] = (j - i <= 2 ? s[i] == s[j] : (p[i + 1][j - 1] && s[i] == s[j]));
            }
        }
        for (int i = 2; i < n; i++) {
            if (!p[i][n - 1]) continue;
            for (int j = 0; j < i - 1; j++) {
                if (p[0][j] && p[j + 1][i - 1]) return true;
            }
        }
        return false;
    }
};
