//
//  main.cpp
//  周赛的第一题花了我最长的时间。。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countValidWords(string sentence) {
        int res = 0;
        stringstream ss(sentence);
        vector<string> v;
        string tmp;
        while (ss >> tmp) {
            v.push_back(tmp);
        }
        for (auto &s: v) {
            int gang = 0, ch = 0, flag = 1;
            for (char c: s) {
                if (c == '-') gang++;
                if (c >= '0' && c <= '9') {
                    flag = 0;
                    break;
                }
                if (c == '!' || c == '.' || c == ',') {
                    ch++;
                }
                if (c >= 'a' && c <= 'z') continue;
            }
            if (gang > 1 || ch > 1) {
                flag = 0;
            }
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '-') {
                    if (i == 0 || !(s[i - 1] >= 'a' && s[i + 1] <= 'z')) flag = 0;
                    if (i == s.size() - 1 || !(s[i + 1] >= 'a' && s[i + 1] <= 'z')) flag = 0;
                }
            }
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] == '!' || s[i] == '.' || s[i] == ',') {
                    flag = 0;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }
};
