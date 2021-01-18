//
//  main.cpp
//  我的做法是先把所有的括号配对，配对的标记上另一个括号的位置，没配对的标记-1
//  新的字符串把所有没配对的括号删掉就可以了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f[100010];
    string minRemoveToMakeValid(string s) {
        string res;
        vector<int> tmp;
        int n = s.size();
        for (int i = 0; i < n; i++) f[i] = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') tmp.push_back(i);
            if (s[i] == ')') {
                if (!tmp.empty()) {
                    f[i] = tmp.back();
                    f[tmp.back()] = i;
                    tmp.pop_back();
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != '(' && s[i] != ')') {
                res.push_back(s[i]);
            } else {
                if (f[i] != -1) res.push_back(s[i]);
            }
        }
        return res;
    }
};
