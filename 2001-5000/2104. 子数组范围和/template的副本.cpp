//
//  main.cpp
//  O(n)的单调栈做法，看了一下比赛时只要求O(n2)，就比较水了
//  注意一边取等号一边不取，技巧类似于经典例题 长方形
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        int lmin[n], rmin[n], lmax[n], rmax[n];
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                rmax[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            rmax[s.top()] = n;
            s.pop();
        }
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                rmin[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            rmin[s.top()] = n;
            s.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                lmax[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            lmax[s.top()] = -1;
            s.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                lmin[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            lmin[s.top()] = -1;
            s.pop();
        }
        long long maxv = 0, minv = 0;
        for (int i = 0; i < n; i++) {
            int r = rmax[i] - 1, l = lmax[i] + 1;
            maxv += (long long)nums[i] * (r - i + 1) * (i - l + 1);
            r = rmin[i] - 1, l = lmin[i] + 1;
            minv += (long long)nums[i] * (r - i + 1) * (i - l + 1);
        }
        return maxv - minv;
    }
};
