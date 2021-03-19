//
//  main.cpp
//  最基本的递归，用递归或者栈就能解决
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto &token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int v1 = s.top(); s.pop();
                int v2 = s.top(); s.pop();
                if (token == "+") s.push(v1 + v2);
                if (token == "-") s.push(v2 - v1);
                if (token == "*") s.push(v1 * v2);
                if (token == "/") s.push(v2 / v1);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
