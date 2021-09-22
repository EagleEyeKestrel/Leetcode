//
//  main.cpp
//  双指针。首先排序是显然的
//  然后维护一个区间，使得其中的元素之差不超过n，那么就尽力凑出这个区间里的连续整数
//  WA一次是因为忘记了可能有重复元素。一种就像下面那样处理，对于重复的数字，也需要替换
//  或者sort之后直接去重也一样
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = n, r = 0, d = 0;
        for (int l = 0; l < n; l++) {
            if (l && nums[l] == nums[l - 1]) d--;
            while (r + 1 < n && nums[r + 1] - nums[l] + 1 <= n) {
                r++;
                if (nums[r] == nums[r - 1]) d++;
            }
            res = min(res, n - (r - l + 1) + d);
        }
        return res;
    }
};
