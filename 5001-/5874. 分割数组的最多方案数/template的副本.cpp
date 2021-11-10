//
//  main.cpp
//  比较简单
//  mp[i]表示 左边-右边的差值为i的 pivot的索引(这里存的pivot和题中的pivot不一样，差1)
//  每次改一个元素，当这个元素在左边的时候，相当于把差值增加k-nums[i]，当这个元素在右边，相当于把差值增加nums[i]-k。二分搜索满足条件的索引个数即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long, vector<int>> mp;
        long long s[n];
        s[0] = nums[0];
        for (int i = 1; i < n; i++) s[i] = s[i - 1] + nums[i];
        for (int i = 0; i < n - 1; i++) {
            long long v1 = s[i], v2 = s[n - 1] - s[i];
            mp[v1 - v2].push_back(i);
        }
        int res = mp[0].size();
        res = max(res, (int)mp[-k + nums[0]].size());
        res = max(res, (int)mp[k - nums[n - 1]].size());
        for (int i = 1; i < n - 1; i++) {
            vector<int> &v1 = mp[-k + nums[i]], &v2 = mp[k - nums[i]];
            int p1 = lower_bound(v1.begin(), v1.end(), i) - v1.begin();
            int p2 = lower_bound(v2.begin(), v2.end(), i) - v2.begin() - 1;
            int tmp1 = v1.size() - p1, tmp2 = p2 + 1;
            res = max(res, tmp1 + tmp2);
        }
        return res;
    }
};
