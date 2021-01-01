//
//  main.cpp
//  不难，s[0] s[1]表示从s[0]开始和为偶数/奇数的数组个数
//  在arr[i]时tmp表明当前和是奇数/偶数，那就要加上之前和为偶数/奇数的个数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long mod = 1e9 + 7, n = arr.size(), tmp = 0, res = 0;
        int s[2];
        s[0] = 1, s[1] = 0;
        for (int i = 0; i < n; i++) {
            tmp = (tmp + arr[i]) % 2;
            res = (res + s[!tmp]) % mod;
            s[tmp]++;
        }
        return res;
    }
};
