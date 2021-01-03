//
//  main.cpp
//  不简单的题，可以看面试题10.03，差不多是同一题
//  这里的讨论标准是nums[l]和nums[mid]的大小关系，来判断哪一边是有序的
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) return false;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[l] < nums[mid]) {
                if (nums[l] <= target && target <= nums[mid]) r = mid;
                else l = mid + 1;
            } else if (nums[l] > nums[mid]) {
                if (nums[mid] < target && target <= nums[r] && nums[l] > target) l = mid + 1;
                else r = mid;
            } else {
                if (nums[l] != target) l++;
                else return true;
            }
        }
        return nums[l] == target;
    }
};
