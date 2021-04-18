//
//  main.cpp
//  很简单的最后一题。。对于32位里的每一位，设arr1里有one1个数此位为1，arr2里有one2个
//  那么会有one1 * one2个数此位为1，如果是奇数，那么结果里这一位就是1
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size(), n = arr2.size(), res = 0;
        for (int k = 0; k < 32; k++) {
            int one1 = 0, one2 = 0;
            for (int x: arr1) {
                if ((x >> k) & 1) one1++;
            }
            for (int x: arr2) {
                if ((x >> k) & 1) one2++;
            }
            if ((long long)one1 * one2 & 1) {
                res ^= (1 << k);
            }
        }
        return res;
    }
};
