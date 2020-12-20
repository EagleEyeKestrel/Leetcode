//
//  main.cpp
//  这次做想到了，用异或。。但是发现题目是递增的？靠。。

//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int num: nums) res ^= num;
        for (int i = 0; i <= n; i++) res ^= i;
        return res;
    }
};
/*
 class Solution {
 public:
     int missingNumber(vector<int>& nums) {
         int n = nums.size();
         int l = 0, r = n - 1;
         while (l < r) {
             int mid = (l + r) >> 1;
             if (nums[mid] != mid) {
                 r = mid;
             } else {
                 l = mid + 1;
             }
         }
         return nums[l] == l ? l + 1 : l;
     }
 };
 */
