//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string reformat(string s) {
        int cnt1 = 0, cnt2 = 0;
        string s1, s2, res;
        for (char c: s) {
            if (islower(c)) cnt1++, s1.push_back(c);
            else cnt2++, s2.push_back(c);
        }
        if (abs(cnt1 - cnt2) > 1) return "";
        int i = 0, j = 0;
        if (cnt1 >= cnt2) {
            while (i < s1.size() && j < s2.size()) {
                res.push_back(s1[i++]);
                res.push_back(s2[j++]);
            }
            if (i < s1.size()) res.push_back(s1[i++]);
        } else {
            while (i < s1.size() && j < s2.size()) {
                res.push_back(s2[j++]);
                res.push_back(s1[i++]);
            }
            if (j < s2.size()) res.push_back(s2[j++]);
        }
        return res;
    }
};
