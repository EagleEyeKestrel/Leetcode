//
//  main.cpp
//  对每个数字计数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[110];
        memset(cnt, 0, sizeof(cnt));
        for(int num: nums) cnt[num]++;
        for(int i = 1; i <= 100; i++) cnt[i] += cnt[i - 1];
        vector<int> res;
        for(int num: nums) {
            res.push_back(num ? cnt[num - 1] : 0);
        }
        return res;
    }
};
