//
//  main.cpp
//  其实就是二分找大于等于target的第一个数，除非target最大要返回n
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n || target < nums[0]) return 0;
        if (target > nums[n - 1]) return n;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
