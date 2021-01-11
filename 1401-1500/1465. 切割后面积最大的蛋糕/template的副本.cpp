//
//  main.cpp
//  不难，找到两个方向切割的最大间隔相乘即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int f(int h, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int res = max(cuts[0], h - cuts.back()), n = cuts.size();
        for (int i = 1; i < n; i++) {
            res = max(res, cuts[i] - cuts[i - 1]);
        }
        return res;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int res1 = f(h, horizontalCuts);
        int res2 = f(w, verticalCuts);
        return (long long)res1 * res2 % mod;
    }
};
