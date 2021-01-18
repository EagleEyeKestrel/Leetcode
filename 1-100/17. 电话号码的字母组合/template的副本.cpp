//
//  main.cpp
//  挺无聊的题，对第i个数字，穷举前i-1的可能情况，添加第i个数字的所有情况
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        unordered_map<int, vector<char>> mp;
        mp[2] = { 'a', 'b', 'c' };
        mp[3] = { 'd', 'e', 'f' };
        mp[4] = { 'g', 'h', 'i' };
        mp[5] = { 'j', 'k', 'l' };
        mp[6] = { 'm', 'n', 'o' };
        mp[7] = { 'p', 'q', 'r', 's' };
        mp[8] = { 't', 'u', 'v' };
        mp[9] = { 'w', 'x', 'y', 'z' };
        res.push_back("");
        for (char c: digits) {
            int n = res.size();
            vector<string> tmp;
            for (string s: res) {
                for (char w: mp[c - '0']) {
                    s.push_back(w);
                    tmp.push_back(s);
                    s.pop_back();
                }
            }
            res = tmp;
        }
        return res;
    }
};
