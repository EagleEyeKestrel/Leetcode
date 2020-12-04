//
//  main.cpp
//  典型的双指针，p1记录当前遍历到了哪里，p2是删除重复元素之后的指针位置
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = 0, tmp = 0;
        while(p1 < n) {
            if(p1 && nums[p1] == nums[p1 - 1]) tmp++;
            else tmp = 1;
            if(tmp < 3) {
                nums[p2++] = nums[p1++];
            } else {
                p1++;
            }
        }
        return p2;
    }
};
