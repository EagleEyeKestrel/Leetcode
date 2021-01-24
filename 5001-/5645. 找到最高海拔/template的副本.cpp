//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, tmp = 0;
        for (int x: gain) {
            tmp += x;
            res = max(res, tmp);
        }
        return res;
    }
};
