//
//  main.cpp
//  一开始居然没想到O(n)的解法。。好菜
//  哈希表把所有数建个集合。然后每次从一段连续序列的开始点开始计数，取最大值
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            if (s.count(*it - 1)) continue;
            int tmpl = 0, tmpv = *it;
            while(s.count(tmpv)) {
                tmpl++, tmpv++;
            }
            res = max(res, tmpl);
        }
        return res;
    }
};
