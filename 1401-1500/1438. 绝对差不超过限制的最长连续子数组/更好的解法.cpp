//
//  main.cpp
//  更简洁的解法，滑动窗口的本质是双指针
//  对于r，我们的需求是维护前一段的最大值和最小值，来确定l
//  用map或者multiset，可以很快速的得到
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), l = 0, res = 0;
        map<int, int> m;
        for (int r = 0; r < n; r++) {
            m[nums[r]]++;
            while (m.rbegin()->first - m.begin()->first > limit) {
                m[nums[l]]--;
                if (m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
