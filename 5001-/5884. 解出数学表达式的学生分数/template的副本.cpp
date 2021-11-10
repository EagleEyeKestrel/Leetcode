//
//  main.cpp
//  真的很无聊的题，记忆化搜索，但这题必须要加个<=1000的剪枝，不加就过不了，哎，卡了一个小时
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int m;
    unordered_set<int> cache[40][40];
    void dfs(string &s, int l, int r) {
        if (l > r) return;
        if (!cache[l][r].empty()) {
            return;
        }
        if (l == r) {
            cache[l][r] = {s[l] - '0'};
            return;
        }
        unordered_set<int> b;
        for (int op = l + 1; op < r; op += 2) {
            dfs(s, l, op - 1);
            dfs(s, op + 1, r);
            if (l > op - 1 || r < op + 1) continue;
            for (int val1: cache[l][op - 1]) {
                for (int val2: cache[op + 1][r]) {
                    if (s[op] == '+') {
                        if (val1 + val2 <= 1000) b.insert(val1 + val2);
                    }
                    else {
                        if (val1 * val2 <= 1000) b.insert(val1 * val2);
                    }
                }
            }
        }
        cache[l][r] = b;
        return;
    }
    int scoreOfStudents(string s, vector<int>& answers) {
        m = s.size();
        int correct = 0, cur = 1, num = 0;
        for (int i = 0; i < m; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = s[i] - '0';
                if (i != m - 1) continue;
            }
            if (s[i] == '*' || s[i] == '+' || i == m - 1) {
                cur *= num;
            }
            if (s[i] == '+' || i == m - 1) {
                correct += cur;
                cur = 1;
            }
            num = 0;
        }
        dfs(s, 0, m - 1);
        unordered_set<int> res = cache[0][m - 1];
        int ans = 0;
        for (int x: answers) {
            if (x == correct) ans += 5;
            else if (res.count(x)) ans += 2;
        }
        return ans;
    }
};
