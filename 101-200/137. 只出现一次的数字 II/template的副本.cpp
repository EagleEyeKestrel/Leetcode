//
//  main.cpp
//  这么简单的题居然没想到。。对32位每一位记录出现次数，发现%3不为0，那一定就有出现1次的数啊
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i, cnt = 0;
            for (int num: nums) {
                if (num & mask) cnt++;
            }
            if (cnt % 3) {
                res = res | mask;
            }
        }
        return res;
    }
};
