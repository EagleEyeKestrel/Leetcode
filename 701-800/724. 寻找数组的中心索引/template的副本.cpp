//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), tmp = 0;
        if (!n) return -1;
        int r[n];
        r[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) r[i] = r[i + 1] + nums[i + 1];
        for (int i = 0; i < n; i++) {
            if (i) tmp += nums[i - 1];
            if (tmp == r[i]) return i;
        }
        return -1;
    }
};
