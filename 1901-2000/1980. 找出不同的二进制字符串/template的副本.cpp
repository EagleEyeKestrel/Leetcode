//
//  main.cpp
//  一种思路是穷举0到2^n-1，逐个比较
//  一种更好的思路是，因为规定每个二进制串是n位，同时也只有n个
//  所以我们可以遍历n个字符串，使结果字符串和nums[i][i]取反
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res;
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(1 ^ nums[i][i]);
        }
        return res;
    }
};
