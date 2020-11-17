//
//  main.cpp
//  stl是有这个标准函数的，可以直接用
//  如果要用朴素方法可以这样。考虑1587654321, l到r表示最后一段最长的降序
//  5和6换位置，然后对后面排序。如果整个数字是降序，就对应l < 0, 整体直接排序
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

/*
 class Solution {
 public:
     void nextPermutation(vector<int>& nums) {
         int n = nums.size();
         int l = n - 2, r = n - 1;
         while(l >= 0 && nums[l] >= nums[l + 1]) l--;
         if(l >= 0) {
             while(nums[r] <= nums[l]) r--;
             swap(nums[l], nums[r]);
         }
         sort(nums.begin() + l + 1, nums.end());
     }
 };
 */
