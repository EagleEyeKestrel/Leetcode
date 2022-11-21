//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            for (int j = max(0, i - k); j <= i + k && j < n; j++) {
                if (nums[j] == key) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};