//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                if (j != i) tmp.push_back(nums[j]);
            }
            int flag = 1;
            for (int j = 0; j < tmp.size() - 1; j++) {
                if (tmp[j] >= tmp[j + 1]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};
