//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        pair<int,int> cnt[m];
        for(int i = 0; i < m; i++) {
            int tmp = 0;
            for(int j = 0; j < n; j++) {
                tmp += mat[i][j];
            }
            cnt[i] = {tmp, i};
        }
        vector<int> res;
        sort(cnt, cnt + m);
        for(int i = 0; i < k; i++) {
            res.push_back(cnt[i].second);
        }
        return res;
    }
};
