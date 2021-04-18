//
//  main.cpp
//  用STL可以秒解，穷举j，维护在范围内的i，可以用multiset不断删除，也可以用map记录下标
//  这个题卡long很严重。。注意s也要设为long，否则s.lower_bound()一个long会出问题？
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long> s;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) s.erase(s.find(nums[i - k - 1]));
            auto it = s.lower_bound((long)nums[i] - t);
            if (it != s.end() && *it <= (long)nums[i] + t) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
