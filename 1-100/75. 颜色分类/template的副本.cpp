//
//  main.cpp
//  很巧妙的算法，把0和2归位，剩下的1也一定归位了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1, now = 0;
        while(now <= r) {
            if(nums[now] == 1) now++;
            else if(nums[now] == 0) {
                swap(nums[now], nums[l]);
                l++;
                now++;
            } else {
                swap(nums[now], nums[r]);
                r--;
            }
        }
    }
};
