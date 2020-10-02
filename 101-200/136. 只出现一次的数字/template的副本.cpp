//
//  main.cpp
//  多少“拍案叫好的算法“文章的开头就是这道题。。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int num: nums) res = res ^ num;
        return res;
    }
};
