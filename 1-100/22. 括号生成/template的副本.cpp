//
//  main.cpp
//  可以看面试题08.09，搜索或者穷举都可以
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> res;
    void dfs(int l, int r, string tmp, int n) {
        if (l == n && r == n) {
            res.push_back(tmp);
            return;
        }
        if (l < n) {
            dfs(l + 1, r, tmp + "(", n);
        }
        if (r < l) {
            dfs(l, r + 1, tmp + ")", n);
        }
    }
    vector<string> generateParenthesis(int n) {
        string tmp;
        dfs(0, 0, tmp, n);
        return res;
    }
};
