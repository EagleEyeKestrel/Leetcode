//
//  main.cpp
//  mp解法
//  对每个smalls里的字符串，去模式匹配big，这个方法是最快的。mp要熟练啊
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> kmp(string& big, string& s) {
        vector<int> res;
        if (s.empty()) return res;
        int p[1024];
        int m = big.size(), n = s.size();
        p[0] = 0, p[1] = 0;
        for (int i = 1; i < n; i++) {
            int j = p[i];
            while (j && s[i] != s[j]) j = p[j];
            p[i + 1] = (s[i] == s[j] ? j + 1 : 0);
        }
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j && big[i] != s[j]) j = p[j];
            if (big[i] == s[j]) j++;
            if (j == n) res.push_back(i - n + 1);
        }
        return res;
    }
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> res;
        for (auto s: smalls) res.push_back(kmp(big, s));
        return res;
    }
};
