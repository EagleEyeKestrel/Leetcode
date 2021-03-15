//
//  main.cpp
//  主要是括号的处理，用栈记录上一个深度的符号和结果。主要还是调bug
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, n = s.size(), num = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ' && i != n - 1) continue;
            if (isdigit(s[i])) {
                num = num * 10 - '0' + s[i];
                if (i != n - 1) continue;
            }
            
            if (s[i] == '+' || s[i] == '-' || s[i] == ')' || i == n - 1) {
                res += sign * num;
                num = 0;
                if (s[i] == '+') sign = 1;
                if (s[i] == '-') sign = -1;
            }
            if (s[i] == '(') {
                st.push(sign);
                st.push(res);
                res = 0, num = 0, sign = 1;
            } else if (s[i] == ')') {
                int lastres = st.top(); st.pop();
                int lastsign = st.top(); st.pop();
                res = lastres + lastsign * res;
            }
        }
        return res;
    }
};
