//
//  main.cpp
//  另一种思路，将所有元素带上原来的数组编号合并在一个数组里
//  直接排序，然后就变成了滑动窗口问题，要保持里面的编号有k种，计算窗口最小值
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res;
        vector<pair<int, int>> v;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            for (int x: nums[i]) {
                v.push_back({ x, i });
            }
        }
        sort(v.begin(), v.end());
        int left = 0, diff = INT_MAX, cnt = 0, n = v.size(), k = nums.size();
        for (int i = 0; i < n; i++) {
            if (m[v[i].second] == 0) cnt++;
            m[v[i].second]++;
            while (cnt == k && left <= i) {
                if (diff > v[i].first - v[left].first) {
                    diff = v[i].first - v[left].first;
                    res = { v[left].first, v[i].first };
                }
                if (m[v[left].second] == 1) cnt--;
                m[v[left].second]--;
                left++;
            }
        }
        return res;
    }
};
