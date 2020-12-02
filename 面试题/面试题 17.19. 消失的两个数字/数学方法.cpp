//
//  main.cpp
//  数学方法，先求出两个缺失的数的和
//  比如说两个数是a, b，(a<b) 那么avg是它们的平均数。
//  然后算出小于等于avg的所有数之和，这里面缺的一个就是a
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        int sum = n * (n + 1) / 2;
        for(int num: nums) sum -= num;
        int avg = sum / 2, smallsum = 0;
        for(int num: nums) if(num <= avg) smallsum += num;
        int small = avg * (avg + 1) / 2 - smallsum;
        return {small, sum - small};
    }
};
