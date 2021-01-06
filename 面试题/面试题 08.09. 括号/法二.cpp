//
//  main.cpp
//  法二，穷举下一个字符是什么，该法较快
//  可以放左括号的条件是左括号还没有达到n个
//  可以放右括号的条件是右括号个数小于左括号
//  字符串用引用比较好
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> res;
    void dfs(int l, int r, string& tmp, int n) {
        if (l == n && r == n) {
            res.push_back(tmp);
            return ;
        }
        if (l < n) {
            tmp.push_back('(');
            dfs(l + 1, r, tmp, n);
            tmp.pop_back();
        }
        if (r < l) {
            tmp.push_back(')');
            dfs(l, r + 1, tmp, n);
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        if (!n) return {};
        if (n == 1) return { "()" };
        string tmp = "";
        dfs(0, 0, tmp, n);
        return res;
    }
};
