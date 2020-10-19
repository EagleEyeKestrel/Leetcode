//
//  main.cpp
//  投票算法，和原来的相比多了可能没有多数元素的情况。
//  所以在cnt==0的时候还需要看一下是否有i+1<n。最后再加一个判断
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
                if(!cnt && i + 1 < n) now = nums[i + 1];
            }
        }
        cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == now) cnt++;
        }
        if(cnt >= n / 2 + 1) return now;
        return -1;
    }
};
