//
//  main.cpp
//  可以发现把nums先翻转，再翻转两个部分，就成了。当然也可以nk次轮转一个元素
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
