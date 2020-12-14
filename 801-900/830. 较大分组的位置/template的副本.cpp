//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int tmp = 0;
        vector<vector<int>> res;
        for (int i = 0; i < s.size(); i++) {
            if (!i || s[i] != s[i - 1]) {
                tmp = 1;
            } else {
                tmp++;
            }
            if (tmp >= 3 && (i == s.size() - 1 || s[i] != s[i + 1])) {
                res.push_back({i - tmp + 1, i});
            }
        }
        return res;
    }
};
