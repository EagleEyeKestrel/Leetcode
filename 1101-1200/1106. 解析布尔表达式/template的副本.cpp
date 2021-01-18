//
//  main.cpp
//  用的递归，expr处理表达式
//  dealseq处理形如expr, expr, expr这样的序列
//  边界情况是expr中l==r
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f[20010];
    vector<int> dealSeq(string& expression, int l, int r) {
        vector<int> res;
        int nowl = l, depth = 0;
        for (int i = l; i <= r; i++) {
            if (expression[i] == '(') depth++;
            if (expression[i] == ')') depth--;
            if (!depth && (i == r || expression[i + 1] == ',')) {
                res.push_back(expr(expression, nowl, i));
                nowl = i + 2;
            }
        }
        return res;
    }
    bool NOT(string& expression, int l, int r) {
        bool tmp = expr(expression, l, r);
        return !tmp;
    }
    bool OR(string& expression, int newl, int newr) {
        vector<int> res = dealSeq(expression, newl, newr);
        for (int x: res) {
            if (x) return true;
        }
        return false;
    }
    bool AND(string& expression, int newl, int newr) {
        vector<int> res = dealSeq(expression, newl, newr);
        for (int x: res) {
            if (x == 0) return false;
        }
        return true;
    }
    bool expr(string& expression, int l, int r) {
        if (l == r) {
            return expression[l] == 't';
        }
        int newl = l + 2, newr = f[l + 1] - 1;
        if (expression[l] == '!') {
            return NOT(expression, newl, newr);
        }
        if (expression[l] == '|') {
            return OR(expression, newl, newr);
        }
        return AND(expression, newl, newr);
    }
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (expression[i] == '(') {
                s.push(i);
            }
            if (expression[i] == ')') {
                f[s.top()] = i;
                f[i] = s.top();
                s.pop();
            }
        }
        return expr(expression, 0, n - 1);
    }
};
