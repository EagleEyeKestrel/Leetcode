//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int cnt[256];
        memset(cnt, 0, sizeof(cnt));
        for(int num: nums) cnt[num + 100]++;
        sort(nums.begin(), nums.end(), [cnt](int a, int b) {
            if(cnt[a + 100] == cnt[b + 100]) {
                return a > b;
            }
            return cnt[a + 100] < cnt[b + 100];
        });
        return nums;
    }
};
