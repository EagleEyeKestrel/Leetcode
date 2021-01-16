//
//  main.cpp
//  浪费时间
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string m[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    string reformatDate(string date) {
        int n = date.size(), p1, p2;
        for (int i = 0; i < n; i++) {
            if (date[i] == ' ') {
                p1 = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (date[i] == ' ') {
                p2 = i;
            }
        }
        unordered_map<string, int> mp;
        for (int i = 0; i < 12; i++) mp[m[i]] = i + 1;
        string s1 = date.substr(0, p1), s2 = date.substr(p1 + 1, 3), res = date.substr(p2 + 1);
        res.push_back('-');
        int m = mp[s2];
        if (m < 10) res.push_back('0');
        res += to_string(m) + "-";
        if (s1.size() == 3) res.push_back('0');
        res += s1.substr(0, s1.size() - 2);
        return res;
    }
};
