//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string a[10];
        string tmp;
        int n = 0;
        while (ss >> tmp) {
            a[tmp.back() - '0'] = tmp.substr(0, tmp.size() - 1);
            n++;
        }
        string res;
        for (int i = 1; i <= n; i++) {
            res += a[i];
            if (i != n) res.push_back(' ');
        }
        return res;
    }
};
