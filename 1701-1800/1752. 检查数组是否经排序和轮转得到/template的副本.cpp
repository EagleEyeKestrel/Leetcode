//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            int flag = 1;
            for (int j = 0; j < n; j++) {
                if (nums[(i + j) % n] != v[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};
