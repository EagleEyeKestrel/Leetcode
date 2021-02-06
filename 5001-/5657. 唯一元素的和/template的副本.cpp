//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int cnt[110];
        memset(cnt, 0, sizeof(cnt));
        for (int num: nums) cnt[num]++;
        int res = 0;
        for (int i = 1; i <= 100; i++) {
            if (cnt[i] == 1) res += i;
        }
        return res;        
    }
};
