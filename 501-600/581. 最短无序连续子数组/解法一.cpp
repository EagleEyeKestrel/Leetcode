//
//  main.cpp
//  法一，比较简单，排序之后从两头开始比较
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] != nums[i]) {
                l = i;
                break;
            }
        }
        if (l == -1) return 0;
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] != nums[i]) {
                r = i;
                break;
            }
        }
        return r - l + 1;
    }
};
