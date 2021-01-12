//
//  main.cpp
//  前缀和的题目，既然要移除之后整除p，现在的总和模p是s[n]%p
//  说明要找长度最短的子数组，元素和模p也是s[n]%p
//  哈希表存一下之前每个点的模P余数，边遍历边存即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) s[i] = (s[i - 1] + nums[i - 1]) % p;
        if (s[n] == 0) return 0;
        unordered_map<int, int> mp;
        mp[0] = 0;
        int target = s[n], res = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (mp.count((s[i] - target + p) % p)) {
                res = min(res, i - mp[(s[i]- target + p) % p]);
            }
            mp[s[i]] = i;
        }
        return res == INT_MAX || res == n ? -1 : res;
    }
};
