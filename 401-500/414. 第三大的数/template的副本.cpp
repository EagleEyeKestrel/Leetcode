//
//  main.cpp
//  遍历三遍。。哈哈哈铁O(n)
//  注意有个用例[1,2,INT_MIN]，很容易错
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size(), flag = 0;
        if (n <= 2) return max(nums[0], n == 2 ? nums[1] : INT_MIN);
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int num: nums) max1 = max(max1, num);
        for (int num: nums) {
            if (num > max2 && num != max1) max2 = num;
        }
        if (max2 == INT_MIN) return max1;
        for (int num: nums) {
            if (num != max1 && num != max2) {
                flag = 1;
                max3 = max(max3, num);
            }
        }
        return flag ? max3 : max1;

    }
};
