//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/117878893
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int s[100010];
    int sumOfFlooredPairs(vector<int>& nums) {
        int n = nums.size();
        memset(s, 0, sizeof(s));
        for (int num: nums) s[num]++;
        for (int i = 1; i <= 1e5 + 9; i++) s[i] += s[i - 1];
        long long res = 0;
        for (int i = 1; i < 100010; i++) {
            for (int j = 1; j * i < 100010; j++) {
                int l = j * i, r = min((long long)100009, (long long)(j + 1) * i - 1);
                long long cnt2 = s[r] - s[l - 1], cnt1 = s[i] - s[i - 1];
                res = (res + cnt1 * cnt2 * j % mod) % mod;
            }
        }
        return res;
    }
};
