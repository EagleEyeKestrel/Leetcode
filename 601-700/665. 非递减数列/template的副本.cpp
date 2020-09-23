//
//  main.cpp
//  其实感觉这easy算挺难的了。。
//  一个注意点，要比i和i+1，不要比i-1，这样调整的只会是i和i+1，不会修改已经确定的元素
//  第二个，nums[i+1]<nums[i-1]，不能有等号！等于的时候，更优解是改nums[i]
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag = 0, n = nums.size();
        if(n < 3) return true;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                if(flag) return false;
                flag = 1;
                if(!i) nums[i] = nums[i + 1];
                else {
                    if(nums[i + 1] < nums[i - 1]) nums[i + 1] = nums[i];
                    else nums[i] = nums[i - 1];
                }
            }
        }
        return true;
    }
};
