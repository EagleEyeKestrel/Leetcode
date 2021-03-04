//
//  main.cpp
//  基础的搜索回溯
//  p预处理一下子串是否回文，然后进行dfs
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[1010][1010];
    void dfs(string& s, int start, vector<vector<string>>& res, vector<string>& tmp) {
        if (start == s.size()) {
            res.push_back(tmp);
            return;
        }
        for (int j = start; j < s.size(); j++) {
            if (p[start][j]) {
                tmp.push_back(s.substr(start, j - start + 1));
                dfs(s, j + 1, res, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; i++) p[i][i] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                p[i][j] = (s[i] == s[j] && (j == i + 1 || p[i + 1][j - 1]));
            }
        }
        vector<vector<string>> res;
        vector<string> tmp;
        dfs(s, 0, res, tmp);
        return res;
    }
};
