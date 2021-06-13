//
//  main.cpp
//  显然可贪心，所以排序双指针
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1, res = 0;
        while(l < r) {
            if(nums[l] + nums[r] < k) {
                l++;
            } else if(nums[l] + nums[r] > k) {
                r--;
            } else {
                l++;
                r--;
                res++;
            }
        }
        return res;
    }
};
