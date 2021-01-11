//
//  main.cpp
//  法二，比如找右端点r，应该是r之前还有数字比nums[r]更大。
//  找到最大的r。同理找到 最小的l。可以做到O(n)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), minv = INT_MAX, maxv = INT_MIN;
        int r = -1, l = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < maxv) r = i;
            maxv = max(maxv, nums[i]);
            if (nums[n - 1 - i] > minv) l = n - 1 - i;
            minv = min(minv, nums[n - 1 - i]);
        }
        if (r == -1) return 0;
        return r - l + 1;
    }
};
