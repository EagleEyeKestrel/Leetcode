//
//  main.cpp
//  穷举最左边一个括号的深度(1到n-1)，或者就是一个()包裹着的
//  该法较慢
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (!n) return {};
        if (n == 1) return { "()" };
        unordered_set<string> se;
        vector<string> n_minus_one = generateParenthesis(n - 1);
        for (string& s: n_minus_one) se.insert("(" + s + ")");
        for (int i = 1; i < n; i++) {
            vector<string> v1 = generateParenthesis(i);
            vector<string> v2 = generateParenthesis(n - i);
            for (string& s1: v1) {
                for (string& s2: v2) {
                    se.insert(s1 + s2);
                }
            }
        }
        vector<string> res(se.begin(), se.end());
        return res;
    }
};
