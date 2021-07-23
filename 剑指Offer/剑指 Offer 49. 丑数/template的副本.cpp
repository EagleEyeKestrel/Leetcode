//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res = {1};
        int i1 = 0, i2 = 0, i3 = 0;
        while (res.size() < n) {
            int tmp = min(2 * res[i1], min(3 * res[i2], 5 * res[i3]));
            res.push_back(tmp);
            if (res[i1] * 2 == tmp) i1++;
            if (res[i2] * 3 == tmp) i2++;
            if (res[i3] * 5 == tmp) i3++;
        }
        return res.back();
    }
};
