//
//  main.cpp
//  首先，如果存在最长特殊序列，那么一定是strs里的某个整个字符串。
//  因为如果子串是一个特殊序列，那么整个字符串一定也是。
//  从长度由大到小遍历，f函数判断s是不是t的子序列
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;
        while (i < m) {
            while (j < n && t[j] != s[i]) j++;
            if (j == n) return 0;
            i++, j++;
        }
        return 1;
    }
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end(), [](auto &a, auto &b) {
            return a.size() < b.size();
        });
        for (int i = n - 1; i >= 0; i--) {
            int flag = 1;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (f(strs[i], strs[j])) {
                    flag = 0;
                    break;
                }
            }
            if (flag) return strs[i].size();
        }
        return -1;
    }
};
