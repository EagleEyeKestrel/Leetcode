//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        vector<string> v;
        string tmp;
        while (ss >> tmp) {
            v.push_back(tmp);
        }
        set<char> se;
        for (char c: brokenLetters) se.insert(c);
        int res = 0;
        for (auto &word: v) {
            int flag = 1;
            for (char c: word) {
                if (se.count(c)) {
                    flag = 0;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }
};
