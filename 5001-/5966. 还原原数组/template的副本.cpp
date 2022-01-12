//
//  main.cpp
//  数据范围是n^2，考虑到其实就是把nums变成x 和 x+2k的组合
//  考虑排序之后nums[0]和nums[i]配对
//  然后就可以双指针确定所有的配对，依次检查即可。不难，但是debug了挺久
//  主要是忘记了标记vis，以及l走完就要先标记vis[l] 否则r可能会和l重合
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size() / 2;
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 1; i < n + n; i++) {
            if ((nums[i] - nums[0]) % 2) continue;
            res.clear();
            int k = (nums[i] - nums[0]) / 2;
            if (k <= 0) continue;
            int ok = 1;
            int vis[2 * n];
            memset(vis, 0, sizeof(vis));
            vis[0] = 1;
            vis[i] = 1;
            res.push_back(nums[0] + k);
            int l = 1, r = 1;
            while (l < n + n) {
                while (l < n + n && vis[l]) l++;
                if (l == n + n) break;
                vis[l] = 1;
                while (r < n + n && (vis[r] || nums[r] < nums[l] + k * 2)) r++;
                if (r == n + n) {
                    ok = 0;
                    break;
                }
                if (nums[r] == nums[l] + 2 * k) res.push_back(nums[l] + k);
                else {
                    ok = 0;
                    break;
                }
                vis[r] = 1;
                l++, r++;
            }
            if (ok && res.size() == n) {
                return res;
            }
        }
        return {};
    }
};
