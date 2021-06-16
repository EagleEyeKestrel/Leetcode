//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size(), one = 0, zero = 0, tmp1 = 0, tmp0 = 0;
        for (char c: s) {
            if (c == '1') {
                tmp1++;
                tmp0 = 0;
                one = max(one, tmp1);
            } else {
                tmp0++;
                tmp1 = 0;
                zero = max(zero, tmp0);
            }
        }
        return one > zero;
    }
};
