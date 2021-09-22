//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(), res = 0;
        int lmax[n], rmin[n];
        lmax[1] = nums[0];
        for (int i = 2; i < n; i++) lmax[i] = max(nums[i - 1], lmax[i - 1]);
        rmin[n - 2] = nums[n - 1];
        for (int i = n - 3; i >= 0; i--) rmin[i] = min(nums[i + 1], rmin[i + 1]);
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > lmax[i] && nums[i] < rmin[i]) res += 2;
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) res++;
        }
        return res;
    }
};
