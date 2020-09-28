//
//  main.cpp
//  第一反应是找出所有差值然后排序。。但这一定超时
//  然后发现将nums排序后，可以双指针数 <= mid的差值对有多少对。
//  要注意，由于cnt包括了 <= mid的所有差值
//  所以当cnt < k，差值一定比mid大
//  但cnt > k时不一定差值就一定比mid小，因为可能这个差值出现了多次
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int f(vector<int> &nums, int mid) {
        int l = 0, n = nums.size(), res = 0;
        for(int r = 0; r < n; r++) {
            while(l < r && nums[l] < nums[r] - mid) l++;
            res += r - l;
        }
        return res;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 1e6;
        sort(nums.begin(), nums.end());
        while(l < r) {
            int mid = (l + r) >> 1;
            int cnt  = f(nums, mid);
            if(cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
