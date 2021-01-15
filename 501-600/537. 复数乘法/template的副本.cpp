//
//  main.cpp
//  水题，字符串基本操作
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int m = a.size(), n = b.size();
        int p1 = a.find('+'), p2 = b.find('+');
        int r1 = stoi(a.suabstr(0, p1)), r2 = stoi(b.substr(0, p2));
        int v1 = stoi(a.substr(p1 + 1, m - p1 - 1));
        int v2 = stoi(b.substr(p2 + 1, n - p2 - 1));
        int r = r1 * r2 - v1 * v2, v = r1 * v2 + r2 * v1;
        return to_string(r) + "+" + to_string(v) + "i";
    }
};
