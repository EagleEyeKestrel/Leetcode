//
//  main.cpp
//  我第一次的解法，二分答案，O(n)验证
//  对于一个确定的长度，就变成了滑动窗口。同时维护滑动窗口的最大值，最小值，看能否有一个区间满足极差<=limit
//  时间很慢，只击败5%，是个O(nlogn)的解法，但是应该常数比较大
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int check(int l, vector<int>& nums, int limit) {
        deque<int> qmax, qmin;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!qmax.empty() && qmax.front() <= i - l) qmax.pop_front();
            while (!qmax.empty() && nums[qmax.back()] <= nums[i]) qmax.pop_back();
            qmax.push_back(i);

            while (!qmin.empty() && qmin.front() <= i - l) qmin.pop_front();
            while (!qmin.empty() && nums[qmin.back()] >= nums[i]) qmin.pop_back();
            qmin.push_back(i);
            if (i >= l - 1 && nums[qmax.front()] - nums[qmin.front()] <= limit) return true;
        }
        return false;
    }
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid, nums, limit)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
