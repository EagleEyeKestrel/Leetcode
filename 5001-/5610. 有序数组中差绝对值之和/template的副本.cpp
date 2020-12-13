//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int s[n + 1];
        s[0] = 0;
        for(int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        for(int i = 1; i <= n; i++) {
            res.push_back((i - 1) * nums[i - 1] - (s[i - 1]) + s[n] - s[i] - (n - i) * nums[i - 1]);
        }
        return res;
    }
};
