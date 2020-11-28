//
//  main.cpp
//  经典题，可以借助归并排序实现
//  在每次merge之前，双指针法记录一下左右两组翻转对的数量，这是O(n)的，所以对总的时间复杂度没有影响
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeAndSort(nums, 0, n - 1);
    }
    int mergeAndSort(vector<int>& nums, int l, int r) {
        if(l >= r) return 0;
        int mid = (l + r) >> 1;
        int res = mergeAndSort(nums, l, mid) + mergeAndSort(nums, mid + 1, r);
        int tmp[r - l + 1];
        int j = mid + 1;
        for(int i = l; i <= mid; i++) {
            while(j <= r && nums[j] < nums[i] / 2.0) j++;
            res += j - 1 - mid;
        }
        int p1 = l, p2 = mid + 1, p = 0;
        while(p1 <= mid && p2 <= r) {
            if(nums[p1] <= nums[p2]) tmp[p++] = nums[p1++];
            else tmp[p++] = nums[p2++];
        }
        while(p1 <= mid) tmp[p++] = nums[p1++];
        while(p2 <= r) tmp[p++] = nums[p2++];
        for(int i = l; i <= r; i++) nums[i] = tmp[i - l];
        return res;
    }
};
