//
//  main.cpp
//  以前我连这种题都不会。。
//  排序，确定最大边，由于小的两条边要大于它，就直接双指针啦，O(n2)
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;
        if(n < 3) return 0;
        sort(nums.begin(), nums.end());
        for(int i = 2; i < n; i++) {
            int l = 0, r = i - 1;
            while(l < r) {
                while(l < r && nums[l] + nums[r] <= nums[i]) l++;
                res += r - l;
                r--;
            }
        }
        return res;
    }
};
