//
//  main.cpp
//  把数字放到对应位置上，剩余没在位置上的，本应该对应的数字就是答案
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
