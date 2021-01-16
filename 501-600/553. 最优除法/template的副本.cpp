//
//  main.cpp
//  容易发现 nums[1]一定在分母上，那最好的情况就是 nums[0] * nums[2] * nums[3] ... / nums[1]
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string res = to_string(nums[0]);
        int n = nums.size();
        if (n == 1) return res;
        if (n == 2) return res + "/" + to_string(nums[1]);
        res += "/(";
        for (int i = 1; i < n; i++) {
            res += to_string(nums[i]);
            res.push_back(i == n - 1 ? ')' : '/');
        }
        return res;
    }
};
