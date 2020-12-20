//
//  main.cpp
//  滑动窗口裸题，窗口内不能出现重复数，维护滑动窗口的元素和
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int vis[10010];
        memset(vis, 0, sizeof(vis));
        int n = nums.size(), l = 0, res = 0, tmp = 0;
        for (int r = 0; r < n; r++) {
            while (vis[nums[r]]) {
                tmp -= nums[l];
                vis[nums[l++]] = 0;
            }
            tmp += nums[r];
            vis[nums[r]] = 1;
            res = max(res, tmp);
        }
        return res;
    }
};
