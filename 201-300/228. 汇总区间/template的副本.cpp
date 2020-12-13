//
//  main.cpp
//  模拟
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        int l = 0, r = 0;
        while(l < n) {
            r = l;
            while(r < n - 1 && nums[r + 1] == nums[r] + 1) r++;
            if (l == r) {
                res.push_back(to_string(nums[l]));
                l++;
                continue;
            }
            string tmp = to_string(nums[l]) + "->" + to_string(nums[r]);
            res.push_back(tmp);
            l = r + 1;
        }
        return res;
    }
};
