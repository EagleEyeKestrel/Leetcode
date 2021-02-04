//
//  main.cpp
//  stl法，维护multiset中间那个指针
//  第一次用c++内置的next prev函数
//  每次加入/删除元素的时候，更新中间指针。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<double> s(nums.begin(), nums.begin() + k);
        auto p = next(s.begin(), k / 2);
        for (int i = k; ; i++) {
            int tmp = *p;
            if (k % 2 == 0) tmp = (tmp + *prev(p, 1)) / 2;
            res.push_back(tmp);
            if (i == nums.size()) break;
            s.insert(nums[i]);
            if (nums[i] < *p) p--;
            if (nums[i - k] <= *p) p++;
            s.erase(s.find(nums[i - k]));
        }
        return res;
    }
};
