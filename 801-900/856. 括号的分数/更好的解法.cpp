//
//  main.cpp
//  更好的解法，空间O(1)
//  用tmp表示当前递归深度，一个“（）”的分数。只算连续的()的分数
//  每次进左括号乘2，出右括号/2
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0, n = S.size(), tmp = 1;
        for (int i = 0; i < n; i++) {
            if (S[i] == ')') tmp /= 2;
            else if (S[i] == '(') {
                if (S[i + 1] == ')') {
                    res += tmp;
                    i++;
                }
                else tmp *= 2;
            }
        }
        return res;
    }
};
