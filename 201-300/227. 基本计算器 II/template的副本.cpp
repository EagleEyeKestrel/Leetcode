//
//  main.cpp
//  优先级分成两类，乘除一类，加减一类
//  看作一系列乘除的和差。res记录加减和，cur记录一个乘除式子的值
//  每次遇到符号或者末尾，cur都会更新。遇到加减或者末尾，res会更新
//  op是上一次的符号
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, op = '+', n = s.size(), op2 = '*', cur = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ' && i != n - 1) continue;
            if (isdigit(s[i])) {
                num = 10 * num - '0' + s[i];
                if (i != n - 1) continue;
            }
            if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || i == n - 1) {
                if (op2 == '*') cur *= num;
                if (op2 == '/') cur /= num;
                op2 = s[i];
            }
            if (s[i] == '+' || s[i] == '-' || i == n - 1) {
                op2 = '*';
                if (op == '+') res += cur;
                else res -= cur;
                cur = 1;
                op = s[i];
            }
            num = 0;
        }
        return res;
    }
};
