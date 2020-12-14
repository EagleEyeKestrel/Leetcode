//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> res = {0, 1};
        if(n < 2) return n;
        int maxv = 1;
        for(int i = 2; i <= n; i++) {
            if(i % 2) {
                res.push_back(res[i / 2] + res[i / 2 + 1]);
            } else {
                res.push_back(res[i / 2]);
            }
            maxv = max(maxv, res[i]);
        }
        return maxv;
    }
};
