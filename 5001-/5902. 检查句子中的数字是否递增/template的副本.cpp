//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();
        stringstream ss(s);
        vector<string> v;
        string tmp;
        while (ss >> tmp) {
            v.push_back(tmp);
        }
        vector<int> o;
        for (auto &str: v) {
            int flag = 1;
            for (char c: str) {
                if (!(c >= '0' && c <= '9')) {
                    flag = 0;
                    break;
                }
            }
            if (flag) o.push_back(stoi(str));
        }
        for (int i = 0; i < o.size() - 1; i++) {
            if (o[i] >= o[i + 1]) return false;
        }
        return true;
    }
};
