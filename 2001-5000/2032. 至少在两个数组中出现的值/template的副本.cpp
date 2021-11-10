//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int find(vector<int> &v, int x) {
        for (int val: v) {
            if (val == x) return 1;
        }
        return 0;
    }
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> res;
        for (int i = 0; i <= 100; i++) {
            if (find(nums1, i) + find(nums2, i) + find(nums3, i) >= 2) {
                res.push_back(i);
            }
        }
        return res;
    }
};
