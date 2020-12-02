//
//  main.cpp
//  更应该掌握的应该是异或解法
//  一堆数，只有两个数出现过一次，怎么找？
//  所有数的异或结果，等于这两个数的异或结果，肯定不为0
//  那么可以根据这个异或结果最低的为1的一位，把所有数分成两类
//  并且缺失的两个数，肯定在两类里面，分开了。然后各自异或就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        for(int i = 1; i <= n; i++) nums.push_back(i);
        int xorRes = 0;
        for(int num: nums) xorRes ^= num;
        int res1 = 0, res2 = 0;
        for(int num: nums) {
            if(num & (xorRes & (-xorRes))) {
                res1 ^= num;
            } else {
                res2 ^= num;
            }
        }
        return {res1, res2};
    }
};
