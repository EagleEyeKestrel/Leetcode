//
//  main.cpp
//  这个没想到什么空间O(1)的方法了。。用个哈希表存一下一个数之前最近的索引
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            auto it = m.find(nums[i]);
            if (it != m.end()) {
                if (i - it->second <= k) return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};
