//
//  main.cpp
//  用stringstream更方便
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string tmp, res;
        int cnt = 0;
        while (ss >> tmp) {
            if (res.empty()) res = tmp;
            else res = res + " " + tmp;
            cnt++;
            if (cnt == k) break;
        }
        return res;
    }
};
