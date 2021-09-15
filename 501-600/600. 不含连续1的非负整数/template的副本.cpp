//
//  main.cpp
//  先预处理dp[i],表示i位数字一共有多少种(最高位可以为0)
//  然后对于num,从高位的1开始处理，每次加的内容，对应这个位为0的情况
//  注意比如对于1100...的特殊情况，第一位我们算上了所有0XXX的情况
//  第二位，此时我们剩余的是1000...到1100...的所有数，但由于第二位其实只能为0
//  所以只剩下1000...到10111...，也就是dp[i-1]了
//  如果是正常结束，还要加上自己
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findIntegers(int num) {
        int dp[32];
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < 32; i++) dp[i] = dp[i - 1] + dp[i - 2];
        int res = 0, last = 0;
        for (int i = 31; i >= 1; i--) {
            if ((num >> (i - 1)) & 1) {
                if (!last) {
                    res += dp[i - 1];
                    last = 1;
                } else {
                    return res + dp[i - 1];
                }
            }
            else last = 0;
        }
        return res + 1;
    }
};
