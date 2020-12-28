//
//  main.cpp
//  把对应数字归位，比如2放到第二个数字。最后依次检查哪个位置的数字不对。如果都对，那就说明是n+1
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
