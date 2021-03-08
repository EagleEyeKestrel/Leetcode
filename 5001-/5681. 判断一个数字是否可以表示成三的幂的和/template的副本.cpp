//
//  main.cpp
//  3的幂很少，全部找出来
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> v;
        int tmp = 1, res = n;
        while (tmp < 1e7) {
            v.push_back(tmp);
            tmp *= 3;
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            if (res >= v[i]) {
                res -= v[i];
            }
        }
        return !res;
    }
};
