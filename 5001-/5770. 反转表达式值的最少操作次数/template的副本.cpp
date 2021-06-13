//
//  main.cpp
//  比赛的时候没做出来，但其实思路是有的而且大体是对的
//  用f表示分别转化成0，1需要的次数(其中有一个肯定是0)
//  我当时想的也是用f返回一个pair，但是返回的是<表达式的值，要转化值所需的次数>
//  比赛的时候主要是不知道对于一个a&b|c&d|e..这种顺序表达式怎么处理
//  感觉如果逐个递归处理会超时，实际上不会，因为还是等价于顺序处理
//  而且f表示成转化成0，1的次数 感觉更直观一些
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int pre[100010];
    pair<int, int> f(string& exp, int l, int r) {
        if (l == r) {
            if (exp[l] == '1') return { 1, 0 };
            else return { 0, 1 };
        }
        if (exp[l] == '(' && exp[r] == ')' && pre[r] == l) return f(exp, l + 1, r - 1);
        int mid = r - 1;
        if (exp[r] == ')') mid = pre[r] - 1;
        auto resl = f(exp, l, mid - 1), resr = f(exp, mid + 1, r);
        pair<int, int> res = { INT_MAX, INT_MAX };
        res.first = min(res.first, resl.first + resr.first);
        res.first = min(res.first, resl.first + resr.second + (exp[mid] == '|'));
        res.first = min(res.first, resl.second + resr.first + (exp[mid] == '|'));
        res.second = min(res.second, resl.second + resr.second);
        res.second = min(res.second, resl.first + resr.second + (exp[mid] == '&'));
        res.second = min(res.second, resl.second + resr.first + (exp[mid] == '&'));
        return res;
    }
    int minOperationsToFlip(string expression) {
        int n = expression.size();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (expression[i] == '(') {
                s.push(i);
            }
            if (expression[i] == ')') {
                pre[i] = s.top();
                s.pop();
            }
        }
        auto res = f(expression, 0, n - 1);
        return max(res.first, res.second);
    }
};
