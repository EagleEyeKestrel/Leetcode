//
//  main.cpp
//  挺无聊的搜索题。
//  一种思路，先确定逗号的位置，然后枚举每个数字可以变成的各种数字
//  枚举的时候可以讨论第一个数字和最后一个数字是否为0
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        int n = S.size();
        vector<string> res;
        for (int i = 1; i < n - 2; i++) {
            string s1 = S.substr(1, i), s2 = S.substr(i + 1, n - i - 2);
            vector<string> v1 = dfs(s1), v2 = dfs(s2);
            for (string& a: v1) {
                for (string& b: v2) {
                    res.push_back("(" + a + ", " + b + ")");
                }
            }
        }
        return res;
    }
    vector<string> dfs(string &s) {
        vector<string> res;
        int n = s.size();
        if (n == 1) return { s };
        char c1 = s[0], c2 = s[n - 1];
        if (c1 == '0' && c2 == '0') return res;
        if (c1 == '0') return { "0." + s.substr(1) };
        if (c2 == '0') return { s };
        res.push_back(s);
        for (int i = 1; i < n; i++) {
            res.push_back(s.substr(0, i) + "." + s.substr(i));
        }
        return res;
    }
};
