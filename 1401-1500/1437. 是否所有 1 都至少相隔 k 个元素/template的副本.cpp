//
//  main.cpp
//  这题就简单题的难度。。查看相邻的两个1就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]) {
                if(last >= 0 && i - last - 1 < k) return false;
                last = i;
            }
        }
        return true;
    }
};
