//
//  main.cpp
//  和丑数一样
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> res = {1};
        int i1 = 0, i2 = 0, i3 = 0;
        while (res.size() < k) {
            int tmp = min(3 * res[i1], min(5 * res[i2], 7 * res[i3]));
            res.push_back(tmp);
            if (res[i1] * 3 == tmp) i1++;
            if (res[i2] * 5 == tmp) i2++;
            if (res[i3] * 7 == tmp) i3++;
        }
        return res.back();
    }
};
