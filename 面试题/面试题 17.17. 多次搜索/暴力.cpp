//
//  main.cpp
//  基础的暴力解法，把每一个子串都统计出来索引
//  不加maxl的优化会超时，加了勉强刚好过
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        unordered_map<string, vector<int>> mp;
        int n = big.size(), maxl = 0;
        for (auto s: smalls) maxl = max(maxl, (int)s.size());
        for (int i = 0; i < n; i++) {
            string tmp = "";
            for (int j = i; j < n && j < i + maxl; j++) {
                tmp.push_back(big[j]);
                mp[tmp].push_back(i);
            }
        }
        vector<vector<int>> res;
        for (string& small: smalls) {
            res.push_back(mp[small]);
        }
        return res;
    }
};
