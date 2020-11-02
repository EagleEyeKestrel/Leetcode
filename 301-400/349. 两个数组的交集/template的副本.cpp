//
//  main.cpp
//  借助stl很简单
//  如果不用stl的话，考虑排序之后二分查找，复杂度也就O(nlgn)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.empty() || nums2.empty()) return {};
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        for(auto it = s1.begin(); it != s1.end(); it++) {
            if(s2.count(*it)) {
                res.push_back(*it);
            }
        }
        return res;
    }
};
