//
//  main.cpp
//  栈的解法，简单但很粗暴。。
//  WA了一次，要考虑到&amp;amp;这种情况，第二次不会再抵消了！这里用了个集合去标记哪些&是后来生成的而非字符串本身就有的
//  当然还有很多其他解法，比如双指针
//  （比赛推荐直接python
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string entityParser(string text) {
        string res;
        unordered_set<int> s;
        for (char c: text) {
            res.push_back(c);
            int n = res.size();
            if (n >= 4 && res.substr(n - 4, 4) == "&gt;" && !s.count(n - 4)) {
                for (int i = 0; i < 4; i++) {
                    res.pop_back();
                }
                res.push_back('>');
            }
            if (n >= 4 && res.substr(n - 4, 4) == "&lt;" && !s.count(n - 4)) {
                for (int i = 0; i < 4; i++) {
                    res.pop_back();
                }
                res.push_back('<');
            }
            if (n >= 5 && res.substr(n - 5, 5) == "&amp;" && !s.count(n - 5)) {
                for (int i = 0; i < 5; i++) {
                    res.pop_back();
                }
                res.push_back('&');
                s.insert(res.size() - 1);
            }
            if (n >= 6 && res.substr(n - 6, 6) == "&quot;" && !s.count(n - 6)) {
                for (int i = 0; i < 6; i++) {
                    res.pop_back();
                }
                res.push_back('"');
            }
            if (n >= 6 && res.substr(n - 6, 6) == "&apos;" && !s.count(n - 6)) {
                for (int i = 0; i < 6; i++) {
                    res.pop_back();
                }
                res.push_back('\'');
            }
            if (n >= 7 && res.substr(n - 7, 7) == "&frasl;" && !s.count(n - 7)) {
                for (int i = 0; i < 7; i++) {
                    res.pop_back();
                }
                res.push_back('/');
            }
        }
        return res;
    }
};
