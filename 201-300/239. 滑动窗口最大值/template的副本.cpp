//
//  main.cpp
//  非常重要，也非常基础的题，经常用到，虽然是困难
//  用一个双向队列，保存这个窗口。先排出已经过了的元素
//  然后nums[i]进队列，排除所有比他小的元素，因为之后不可能再作为最大值了（比nums[i]小
//  队列的头就是现在的窗口里的最大值（的索引
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.front() <= i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
