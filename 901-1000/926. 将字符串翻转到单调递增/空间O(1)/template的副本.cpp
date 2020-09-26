//
//  main.cpp
//  dp，最容易想的空间O(1)
//  one和zero表示第i位为1/0的最小操作次数
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        int zero = 0, one = 0;
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '0') {
                one = min(zero, one) + 1;
            } else {
                one = min(zero, one);
                zero++;
            }
        }
        return min(zero, one);
    }
};
