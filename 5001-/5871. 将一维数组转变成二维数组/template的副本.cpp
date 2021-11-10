//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < original.size(); i++) {
            res[i / n][i % n] = original[i];
        }
        return res;
    }
};
