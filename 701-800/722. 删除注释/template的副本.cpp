//
//  main.cpp
//  贼无聊的题，调的错了几次才过
//  用flag表示当前是否遇到过/*
//  tmp是当前行的字符串。
//  大致分为几部分，第一种是普通字符，如果不在flag内，说明是没有被注释掉的字符
//  然后是遇到/的情况，如果是//，而且没在flag内，直接跳到行尾
//  如果是/*，要注意，如果在flag内只能i++而不是i+=2,比如/*s/*/的情况
//  最后是遇到*的情况，如果在flag内好办，如果不在，也只能i++处理一个字符，有*//eee的情况
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        int flag = 0;
        for (auto &s: source) {
            int i = 0;
            string tmp;
            if (flag && !res.empty()) {
                tmp = res.back();
                res.pop_back();
            }
            while (i < s.size()) {
                if (s[i] != '/' && s[i] != '*') {
                    if (!flag) tmp.push_back(s[i]);
                    i++;
                } else if (s[i] == '/') {
                    if (i + 1 < s.size() && s[i + 1] == '/') {
                        if (!flag) break;
                        i += 2;
                    } else if (i + 1 < s.size() && s[i + 1] == '*') {
                        if (flag) {
                            i++;
                        } else {
                            flag = 1;
                            i += 2;
                        }
                    } else {
                        if (!flag) tmp.push_back(s[i]);
                        i++;
                    }
                } else {
                    if (i + 1 < s.size() && s[i + 1] == '/') {
                        if (flag) {
                            flag = 0;
                            i += 2;
                        } else {
                            tmp.push_back('*');
                            i++;
                        }
                    } else {
                        if (!flag) tmp.push_back(s[i]);
                        i++;
                    }
                }
            }
            if (!tmp.empty()) res.push_back(tmp);
        }
        return res;
    }
};
