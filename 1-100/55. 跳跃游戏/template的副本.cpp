//
//  main.cpp
//  甚至不需要dp，直接看当前能够到达的最远距离maxd，不断更新就行
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxd = 0;
        for (int i = 0; i < n; i++) {
            if (maxd < i) return false;
            if (i + nums[i] > maxd) maxd = i + nums[i];
            if (maxd >= n - 1) return true;
        }
        return true;
    }
};
