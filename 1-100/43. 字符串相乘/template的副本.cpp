//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        int r[m + n + 1];
        memset(r, 0, sizeof(r));
        string res;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int t = (num1[i] - '0') * (num2[j] - '0');
                r[(m - 1 - i) + (n - 1 - j)] += t;
            }
        }
        for (int i = 0; i < m + n; i++) {
            r[i + 1] += r[i] / 10;
            r[i] %= 10;
        }
        int flag = 0;
        for (int i = m + n; i >= 0; i--) {
            if (r[i] || i == 0) flag = 1;
            if (flag) res.push_back(r[i] + '0');
        }
        return res;
    }
};
