//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxv = INT_MIN, minv = INT_MAX;
        int maxpos, minpos, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxv) {
                maxv = nums[i];
                maxpos = i;
            }
            if (nums[i] < minv) {
                minv = nums[i];
                minpos = i;
            }
        }
        if (maxpos > minpos) swap(maxpos, minpos);
        return min(minpos + 1, min(n - maxpos, maxpos + 1 + n - minpos));
    }
};
