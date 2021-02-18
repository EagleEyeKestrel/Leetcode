//
//  main.cpp
//  比普通的平衡括号串题目多了个星号，所以关键是怎么处理星号
//  如果碰到右括号，有左括号优先匹配左括号，否则，选择匹配星号
//  最后，看有没有左括号剩余。如果有，从右开始尝试着把星作为右括号去消除左括号。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkValidString(string s) {
        vector<int> l, star;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') l.push_back(i);
            if (c == ')') {
                if (!l.empty()) l.pop_back();
                else if (!star.empty()) star.pop_back();
                else return false;
            }
            if (c == '*') star.push_back(i);
        }
        while (!l.empty() && !star.empty()) {
            if (l.back() > star.back()) return false;
            l.pop_back();
            star.pop_back();
        }
        return l.empty();
    }
};
