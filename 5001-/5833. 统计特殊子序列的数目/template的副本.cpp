//
//  main.cpp
//  用s[i]表示当前以nums[i]这个数结尾的序列有多少个
//  比如nums[i]==0时，那么之前也只能是0，也可能是空，所以以nums[i]结尾的有s[0]+1个，再加上之前所有以0结尾的，就还要再加个s[0]
//  s[1] s[2]同理
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int mod = 1e9 + 7;
        long long n = nums.size(), res = 0;
        long long s[3];
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                s[0] = (s[0] + 1 + s[0]) % mod;
            }
            if (nums[i] == 1) {
                s[1] = (s[0] + s[1] + s[1]) % mod;
            }
            if (nums[i] == 2) {
                s[2] = (s[1] + s[2] + s[2]) % mod;
            }
        }
        return s[2];
    }
};
