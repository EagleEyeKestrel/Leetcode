//
//  main.cpp
//  居然错了三次。。主要是要想到，ull的最大范围大概是10^19，二十位的样子
//  所以这个题用ull 搜索范围刚好够用
//  pos是搜索开始的位置，last是上次的值，cnt表示这是第几段字符串
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int n;
    bool dfs(string& s, int pos, unsigned long long last, int cnt) {
        if (pos == n && cnt > 2) return true;
        bool res = false;
        for (int i = pos; i < min(n, pos + 19); i++) {
            string sub = s.substr(pos, i - pos + 1);
            unsigned long long val = stoull(sub);
            if (cnt == 1 || val == last - 1) {
                res = res || dfs(s, i + 1, val, cnt + 1);
            }
        }
        return res;
    }
    bool splitString(string s) {
        n = s.size();
        return dfs(s, 0, 0, 1);
    }
};
