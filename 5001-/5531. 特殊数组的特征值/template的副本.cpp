//
//  main.cpp
//  稍微想了会儿，最后决定直接排序二分来做
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= 100; i++) {
            int id = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            if(i == n - id) {
                return i;
            }
        }
        return -1;
    }
};
