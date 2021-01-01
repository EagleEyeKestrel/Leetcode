//
//  main.cpp
//  二分法。
//  当nums[mid] < nums[r]时，说明mid到r是完整的一部分(没有旋转过)
//  判断一下target在不在这段
//  当nums[mid] >= nums[r]，说明mid到r里有转折点
//  mid比target还小，说明target肯定在mid右边
//  反之并且target >= nums[l]，说明target在l和mid之间。再否则说明还在右边
//  有几个等号是一定要取的，要注意，比如target <= nums[r]和nums[l] <= target
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) return -1;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[r]) {
                if (nums[mid] <= target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            } else {
                if (nums[mid] < target) l = mid + 1;
                else if (nums[l] <= target) r = mid - 1;
                else l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
};
