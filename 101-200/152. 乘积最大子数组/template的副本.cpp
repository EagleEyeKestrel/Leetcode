//
//  main.cpp
//  很简单的基础dp，但WA了好几次。。
//  不要设pos 和 neg，应该意思是最大数和最小数，这样递推公式更简单
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0];
        int pos = 1, neg = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                pos = max(nums[i], pos * nums[i]);
                neg = min(nums[i], neg * nums[i]);
            } else if (nums[i] == 0) {
                pos = 0, neg = 0;
            } else {
                int oldpos = pos;
                pos = nums[i] * neg;
                neg = min(nums[i], nums[i] * oldpos);
            }
           res = max(res, max(pos, neg));
        }
        return res;
    }
};
