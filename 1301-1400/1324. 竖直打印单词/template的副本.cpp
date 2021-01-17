//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> v;
        stringstream ss(s);
        string tmp;
        int maxl = -1;
        while (ss >> tmp) v.push_back(tmp), maxl = max(maxl, (int)tmp.size());
        vector<string> res(maxl, "");
        for (string &str: v) {
            for (int i = 0; i < maxl; i++) {
                if (i < str.size()) res[i].push_back(str[i]);
                else res[i].push_back(' ');
            }
        }
        for (string &str: res) {
            while (!str.empty() && str.back() == ' ') str.pop_back();
        }
        return res;
    }
};
