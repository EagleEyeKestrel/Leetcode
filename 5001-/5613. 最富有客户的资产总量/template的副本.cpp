//
//  main.cpp
//  vivo周赛第一题，看到这个第一题还以为会很简单。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        int m = accounts.size(), n = accounts[0].size();
        for(int i = 0; i < m; i++) {
            int tmp = 0;
            for(int j = 0; j < n; j++) {
                tmp += accounts[i][j];
            }
            res = max(res, tmp);
        }
        return res;
    }
};
