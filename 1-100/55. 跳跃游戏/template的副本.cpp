//
//  main.cpp
//  甚至不需要dp，直接看当前能够到达的最远距离maxd，不断更新就行
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        for (int i = 0; i < n; i++) {
            if (mx < i)
                return false;
            mx = max(mx, i + nums[i]);
        }
        return true;
    }
};
