//
//  main.cpp
//  我的做法，用个栈存之前的分数，-1代表'('，其他数字代表分数
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int scoreOfParentheses(string S) {
        vector<int> v;
        for (char c: S) {
            if (c == '(') v.push_back(-1);
            else {
                int tmp = 0;
                while (!v.empty() && v.back() != -1) {
                    tmp += v.back();
                    v.pop_back();
                }
                v.pop_back();
                v.push_back(tmp ? tmp << 1 : 1);
            }
        }
        int res = 0;
        for (int x: v) res += x;
        return res;
    }
};
