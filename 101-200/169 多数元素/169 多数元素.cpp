//
//  main.cpp
//  投票算法
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int now = nums[0], cnt = 0;
        for(int i = 0; i < n; i++) {
            if(now == nums[i]) {
                cnt++;
            } else {
                cnt--;
                if(!cnt) now = nums[i + 1];
            }
        }
        return now;
    }
};
