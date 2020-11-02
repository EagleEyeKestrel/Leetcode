//
//  main.cpp
//  记忆化搜索
//  穷举前面第一个分割出去的长度，后面调用递归，然后合并
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    unordered_map<string, vector<string>> m;
    int flag = 0;
    unordered_set<string> se;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(m.count(s)) return m[s];
        if(s.empty()) return {""};
        vector<string> res;
        if(!flag) {
            se = unordered_set(wordDict.begin(), wordDict.end());
            flag = 1;
        }
        for(int l = 1; l <= s.size(); l++) {
            if(se.count(s.substr(0, l))) {
                vector<string> nextDict = wordBreak(s.substr(l), wordDict);
                for(string& str: nextDict) {
                    res.push_back(s.substr(0, l) + (str.empty() ? "" : " " + str));
                }
            }
        }
        m[s] = res;
        return res;
    }
};
